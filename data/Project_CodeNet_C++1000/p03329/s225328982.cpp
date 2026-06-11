#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
using Graphl = vector<vector<ll>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define FOR(itr, v) for (auto itr = (v).begin(); itr != (v).end(); ++itr)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const long long minusINF = -(1LL << 40);
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main()
{
    int n; cin >> n;
    vector<int> c;
    c.push_back(1);
    for (int i = 6; i <= n; i *= 6) c.push_back(i);
    for (int i = 9; i <= n; i *= 9) c.push_back(i);

    vector<ll> dp(110000, INF);
    dp[0] = 0;
    rep(i, n + 1)
    {
        rep(j, c.size())
        {
            if (i >= c[j])
            {
                chmin(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    // rep(i, n + 1)
    // {
    //     cout << dp[i] << " ";
    //     if (i == n) cout << endl;
    // }

    cout << dp[n] << endl;
}