#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MAX_DIGIT = 50;
ll dp[100][2];

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    rep(d, MAX_DIGIT)
    {
        ll mask = 1LL << (MAX_DIGIT - d - 1);

        int num = 0;
        rep(i, n) if (a[i] & mask) num++;

        ll cost0 = mask * num;
        ll cost1 = mask * (n - num);

        if (dp[d][1] >= 0) chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));

        if (dp[d][0] >= 0)
        {
            if (k & mask)
            {
                chmax(dp[d + 1][1], dp[d][0] + cost0);
                chmax(dp[d + 1][0], dp[d][0] + cost1);
            }
            else
            {
                chmax(dp[d + 1][0], dp[d][0] + cost0);
            }

        }
    }
    cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}