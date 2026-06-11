#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;

//typedef
//-------------------------#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s)
{
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}
inline int readInt()
{
    int x;
    scanf("%d", &x);
    return x;
}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a) * (a))
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

//repetition
//------------------------------------------
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define MOD 1000000007

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;

#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const int INF = 2147483647;

const int dxy[5] = {-1, 0, 1, 0, -1};
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

vector<vector<int>> G(100010);
int c[10010];
int ans[10010];
int idx = 0;
int sum = 0;
void dfs(int v, int prev = -1)
{

    ans[v] = c[idx];
    idx++;
    if (prev != -1)
        sum += ans[v];
    for (int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i];
        if (u == prev)
            continue;

        dfs(u, v);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    REP(i, N)
    {
        cin >> c[i];
    }

    sort(c, c + N);
    reverse(c, c + N);

    dfs(0);

    cout << sum << endl;
    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";

        cout << ans[i];
    }
    cout << endl;
}
