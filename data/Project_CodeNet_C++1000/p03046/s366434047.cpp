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
const ll MOD = 1'000'000'007;
// const ll MOD = 998244353;
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

    ll M, K;
    cin >> M >> K;
    ll K_max = bit(M) - 1;
    if(K > K_max){
        cout << -1 << endl;
        return 0;
    }
    if(K == 0){
        rep(i,bit(M)){
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }
    if(K == 1 && M == 1){
        cout << -1 << endl;
        return 0;
    }
    // 1 <= K <= Kmax
    deque<int> ans;
    ans.push_back(K);
    for(int i = 1; i < bit(M); i++){
        if(i == K)continue;
        ans.push_back(i);
        ans.push_front(i);
    }
    ans.push_back(0);
    ans.push_back(K);
    ans.push_back(0);
    for(auto a: ans){
        cout << a << " ";
    }
    cout << endl;
}
