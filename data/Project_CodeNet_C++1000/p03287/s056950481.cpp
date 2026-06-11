#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> b(n);
    b[0]=a[0];
    rep(i,n-1) b[i+1]=b[i]+a[i+1];
    map<ll,ll> mp;
    rep(i,n) mp[b[i]%m]++;
    ll res=0;
    for(auto&p:mp){
        if(p.first==0)res+=p.second;
        res+=(p.second)*(p.second-1)/2;
    }
    cout<<res<<endl;
}

