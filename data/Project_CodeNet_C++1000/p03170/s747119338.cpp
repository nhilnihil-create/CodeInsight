#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld double
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define vc vector
#define rep1(it,v) for(it=v.begin();it!=v.end();it++)
#define ayush ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define input(v) for(auto &it:v)cin>>it
#define inf 100000000007
#define pb push_back

int main()
{
    ll n,k; cin>>n>>k; vc<ll> v1(n), v2(k+5); input(v1);
    rep(i,1,k)
    {
        rep(j,0,n-1)
        {
            if(i>=v1[j] && v2[i-v1[j]]==0) v2[i]=1;
        }
    }
    if(v2[k]) cout<<"First";
    else cout<<"Second"; 
}