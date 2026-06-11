#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    int N;
    cin >> N;
    int ans=1000;
    for(int i=0;i<=N;i++){
        int a=0;
        int s=i;
        while(1){
            a+=s%9;
            s=s/9;
            if(s==0)break;
        }
        s=N-i;
        while(1){
            a+=s%6;
            s=s/6;
            if(s==0)break;
        }
        ans=min(ans,a);
    }
    cout << ans << endl;
}