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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    ll sumA = accumulate(all(A),0LL);
    ll sumB = accumulate(all(B),0LL);
    if(sumB > sumA){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> d(N);
    rep(i,N){
        d[i] = A[i] - B[i];
    }
    sort(all(d));
    ll ans = 0;
    ll hsk_sum = 0;
    rep(i,N){
        if(d[i] < 0){
            ans++;
            hsk_sum += abs(d[i]);
        }

    }
    for(int i = N-1; i >= 0; i--){
        if(d[i] > 0){
            if(hsk_sum <= 0)break;
            hsk_sum -= abs(d[i]);
            ans++;
        }
    }
    cout << ans << endl;
}
