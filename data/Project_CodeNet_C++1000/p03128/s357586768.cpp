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
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const string MINUSINF = "-";
ll match[10] = {2,5,5,4,5,6,3,7,6};
vector<string> dp(11000);

void chmax(string &a, string b)
{
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size())
    {
        if (a < b) a = b;
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    rep(i, 11000) dp[i] = MINUSINF;
    dp[0] = "";

    rep(i, n + 1)
    {
        if (dp[i] == MINUSINF) continue;
        for (auto c : a) chmax(dp[i + match[c - 1]], dp[i] + (char)(c + '0'));
    }

    cout << dp[n] << endl;
}