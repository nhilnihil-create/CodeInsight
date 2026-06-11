#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
#define ALL(v) (v).begin(), (v).end()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
 
#if 1
//-------------
// DUMPマクロ
// https://www.creativ.xyz/dump-cpp-652/
 
// vector
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&& ... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#endif

int N;
int a[16][16];

int dp[(1<<16)-1];
int cost[(1<<16)-1];

void solve(){
    cin >> N;
    
    rep(i,N)rep(j,N) cin >> a[i][j];
    
    rep(i,(1LL<<N)){
        rep(j,N)rep1(k,j,N){
            if((i&(1LL<<j)) && (i&(1LL<<k))) cost[i] += a[j][k];
        }
    }
    
    for (int used = 0; used < (1 << N); used++) { // 使用済みのビット
        int unused = used ^ ((1 << N) - 1); // 未使用のビット
        for (int use = unused; use > 0; use=(use-1)&unused) { // unusedの部分集合を列挙
            if (use <= used) continue;
            // dp遷移を書く
            dp[used|use] = max(dp[used|use], dp[used] + cost[use]);
        }
    }
    
    cout << dp[(1<<N)-1] << endl;
}

signed main(){
    cout << fixed << setprecision(18) << endl;
    cerr << fixed << setprecision(18) << endl;
    solve();
}
