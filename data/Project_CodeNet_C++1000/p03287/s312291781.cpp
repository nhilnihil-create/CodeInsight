#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
typedef long long ll;
using namespace std;
int main(void){
    // Your code here!
    int n;ll m;cin>>n>>m;
    map<ll,int> mp;
    ll res=0;
    vector<ll> b(n+1,0);
    rep(i,n){
        ll a;cin>>a;
        b[i+1]=b[i]+a;
        ll buf=b[i+1]%m;
        if(buf==0)mp[0]++;
        res+=mp[(buf==0)? 0:buf];
        if(buf!=0)mp[buf]++;
    }
    cout<<res<<endl;
}
