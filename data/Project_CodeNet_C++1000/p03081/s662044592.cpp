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
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; string S; cin >> N >> Q >> S;
    vector<char> t(Q),d(Q);
    rep(i,Q) cin >> t[i] >> d[i];
    int lb=-1,ub=N,ans=0;
    while(ub-lb>1){
        int mid=(ub+lb)>>1,now=mid;
        bool ok=false;
        rep(i,Q){
            if (S[now]==t[i]){
                if (d[i]=='L') --now;
                else ++now;
            }
            if (now==-1){ok=true; break;}
            if (now==N) break;
        }
        (ok?lb:ub)=mid;
    }
    ans+=ub;
    lb=-1,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)>>1,now=N-1-mid;
        bool ok=false;
        rep(i,Q){
            if (S[now]==t[i]){
                if (d[i]=='L') --now;
                else ++now;
            }
            if (now==N){ok=true; break;}
            if (now==-1) break;
        }
        (ok?lb:ub)=mid;
    }
    ans+=ub;
    cout << N-ans << endl;
}