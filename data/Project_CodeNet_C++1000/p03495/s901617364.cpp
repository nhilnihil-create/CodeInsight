#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    ll n,k; cin >> n >> k;
    vector<int>d(n+1);
    rep(i,n+1)d[i]=0;
    rep(i,n)
    {
        int a; cin>>a;
        d[a]++;
    }
    sort(d.begin(),d.end());
    ll ans=0;
    for(int i=n;n-i!=k;--i)
    {
        ans +=d[i];
    }

    cout<<n-ans;
    return 0;
}