#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q; string S; cin >> N >> S >> Q;
    rep(i,Q){
        ll k; cin >> k;
        ll ans=0,cnt0=0,cnt1=0,cnt2=0;
        rep(j,N){
            if (j>=k){
                if (S[j-k]=='D') --cnt1,cnt0-=cnt2;
                if (S[j-k]=='M') --cnt2;
            }
            if (S[j]=='D') ++cnt1;
            if (S[j]=='M') ++cnt2,cnt0+=cnt1;
            if (S[j]=='C') ans+=cnt0;
        }
        cout << ans << endl;
    }
}