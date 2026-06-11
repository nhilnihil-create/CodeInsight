#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
#define mp make_pair
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};


int main() {
    ll N,C;
    cin >> N >> C;
    vvl d(C,vl(200005));
    rep(i,N){
        ll s,t,c;
        cin >> s >> t >> c;
        c--;
        s--;
        t--;
        d[c][2*s]++;
        d[c][2*t+1]--;
    }
    vvl s(C,vl(200006,0));
    rep(i,C){
        rep(j,200005){
            s[i][j+1]=s[i][j]+d[i][j];
            if(s[i][j+1]==2){
                s[i][j+1]=1;
                d[i][j+1]++;
            }
        }
    }
    ll ans=0;
    rep(i,200006){
        ll k=0;
        rep(j,C){
            k+=s[j][i];
        }
        ans=max(ans,k);
    }
    cout << ans << endl;
}