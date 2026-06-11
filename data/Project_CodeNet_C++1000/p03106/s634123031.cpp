#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int a,b,k;cin>>a>>b>>k;
    priority_queue<int>pq;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            pq.push(i);
        }
    }
    rep(i,k-1){
        pq.pop();
    }
    int ans=pq.top();
    cout<<ans<<endl;

}