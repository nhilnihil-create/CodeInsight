#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main(){
    int n,kk,p,ans=0;cin>>n>>kk;
    p=min(n,kk);
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    for(int i=0;i<=p;i++){
        int t=0;
        priority_queue<int> q;
        for(int j=0;j<i;j++){
            if(v[j]<0) q.push(-v[j]);
            t+=v[j];
        }
        for(int j=0;j<=p-i;j++){
            int tt=t;priority_queue<int> qq=q;
            for(int k=0;k<j;k++){
                tt+=v[n-1-k];
                if(v[n-1-k]<0) qq.push(-v[n-1-k]);
            }
            for(int k=0;k<kk-i-j;k++) {
                if(qq.empty()) break;
                tt+=qq.top();
                qq.pop();
            }
            ans=max(ans,tt);
        }
    }
    cout<<ans;
}
