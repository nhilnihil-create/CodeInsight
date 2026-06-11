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
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, A, B, C;
vector<int> l;

int rec(int i, int a, int b, int c)
{
    if (i == n)
    {
        if (!a || !b || !c) return MOD;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }

    int ans = rec(i + 1, a, b, c);

    chmin(ans, rec(i + 1, a + l[i], b, c) + (a ? 10 : 0));
    chmin(ans, rec(i + 1, a, b + l[i], c) + (b ? 10 : 0));
    chmin(ans, rec(i + 1, a, b, c + l[i]) + (c ? 10 : 0));

    return ans;
}

int main()
{
    cin >> n >> A >> B >> C;
    l.resize(n);
    rep(i, n) cin >> l[i];

    cout << rec(0, 0, 0, 0) << endl;
}