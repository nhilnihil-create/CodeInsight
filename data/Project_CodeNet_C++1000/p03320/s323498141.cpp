#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
ll s(ll n){
    ll res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
signed main(){
    ll k;cin>>k;
    ll now=1;
    ll ans=1;
    while(k){
        cout<<ans<<endl;
        ll c=ans+now;
        if(c-now*s(c)<=0){
            ans=c;
        }else{
            while(c-now*s(c)>0){
                now*=10;
            }
            ans+=now;
        }
        k--;
    }
}