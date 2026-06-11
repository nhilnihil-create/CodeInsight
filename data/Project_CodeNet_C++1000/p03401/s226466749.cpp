#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
long long fac(ll a){
    long long ans=1;
    while(a>1){
        ans*=a;
        ans%=1000000007;
        a--;
    }
    return ans;
}
int main(){
    ll n;cin >> n;
    vl v(n+2,0);
    rep(i,n)cin >> v[i+1];
    ll ans=0;
    vl info(n+1);
    rep(i,n+1){
        info[i]=abs(v[i+1]-v[i]);
    }
    ans+=abs(v[2]);
    for(int i=2;i<=n;i++){
        ans += info[i];
    }
    cout << ans << endl;
    for(int i=0;i<n-1;i++){
        ans-=info[i+2];
        ans-=abs(v[i+2]-v[i]);
        ans+=info[i];
        ans+=abs(v[i+1]-v[i+3]);
        cout << ans << endl;
    }
}