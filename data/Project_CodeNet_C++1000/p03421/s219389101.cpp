#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

vector<long long> LISLDS(long long N, long long A, long long B) {
    vector<long long> res;
    for (long long i = B-1; i >= 0; --i) res.push_back(i);
    
    if (A == 1) return res;
    
    long long rem = N - B;
    long long p = rem / (A-1);
    long long r = rem % (A-1);
    
    long long b = r;
    long long c = A-1-r;
    
    for (int i = 0; i < b; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p+1; ++j) {
            res.push_back(size + p - j);
        }
    }
    for (int i = 0; i < c; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p; ++j) {
            res.push_back(size + p-1 - j);
        }
    }
    
    return res;
}

void solve(){
    ll N, A, B;
    cin >> N >> A >> B;
    if(!(A + B <= N+1 && A * B >= N)){
        cout << -1 << endl;
        return;
    }
    auto res = LISLDS(N, A, B);
    for(auto x : res) cout << x + 1 << " ";
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}