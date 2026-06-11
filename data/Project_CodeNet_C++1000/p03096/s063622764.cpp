#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

ll dp[202020];
ll cum[202020];

vector<pair<int, int>> runLengthEncoding(vector<int> s) {
    int n = s.size();

    vector<pair<int, int>> res;
    int pre = s[0];
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if (pre != s[i]) {
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({ pre, cnt });
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> C(N);
    REP(i,N) cin >> C[i];
    auto CC = runLengthEncoding(C);
    int n = CC.size();
    dp[0] = 1;
    REP(i,n){
        int c = CC[i].first;
        dp[i + 1] = dp[i] + cum[c];
        dp[i + 1] %= MOD;
        cum[c] += dp[i];
        cum[c] %= MOD;
    }
    cout << dp[n] << endl;
}
