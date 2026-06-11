#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
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

void PrintVector(const vector<int> &vec)
{
    for (auto val : vec)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n, m, c; cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    Graph a(n, vector<int>(m));
    int ans = 0;
    rep(i, n)
    {
        int tmp = 0;
        rep(j, m)
        {
            cin >> a[i][j];
            tmp += (a[i][j] * b[j]);
        }
        if (tmp + c > 0) ans++;
    }

    cout << ans << endl;
}