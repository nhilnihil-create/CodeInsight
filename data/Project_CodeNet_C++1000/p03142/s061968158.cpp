#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define repr(i, a, n) for (ll i = n - 1; (ll)a <= i; i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 + 99);
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T mpow(T a, T n)
{
    T res = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n, vector<int>(0));
    vector<int> in(n, 0), ans(n);

    rep(i, 0, n + m - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].pb(b);
        in[b]++;
    }

    int root;
    rep(i, 0, n)
    {
        if (!in[i])
        {
            root = i;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    q.push(0);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int mae = q.front();
        q.pop();
        ans[now] = mae;

        rep(i, 0, siz(e[now]))
        {
            if (in[e[now][i]] <= 1)
            {
                q.push(e[now][i]);
                q.push(now + 1);
            }
            else
            {
                in[e[now][i]]--;
            }
        }
    }

    rep(i, 0, n)
    {
        cout << ans[i] << endl;
    }
}