#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
const int sz = 100010;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, C;
    cin >> N >> C;
    vec<int> s(N),t(N),c(N);
    vvec<int> imos(30, vec<int>(sz,0));
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
        imos[c[i]][s[i]]++;
        imos[c[i]][t[i]]--;
    }
    rep(j,30)rep(i,sz-1){
        imos[j][i+1] += imos[j][i];
    }
    rep(j,30)rep(i,sz-1){
        if(imos[j][i+1] == 1 && imos[j][i] == 0){
            imos[j][i] = 1;
        }
    }
    ll ans = 0;
    rep(i,sz){
        ll tmp = 0;
        rep(j,30){
            tmp += imos[j][i];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}