#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = int;
using Graph = vector<vector<Edge>>;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;
const ll nmax = 8;
const ll INF = 1e9;
bool graph[nmax][nmax];
vector<vector<ll>> dist = vector<vector<ll>>(nmax, vector<ll>(nmax, INF));
void warshall_floyd(ll n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

class UnionFind
{
public:
    vector<ll> Parent;

    UnionFind(ll N)
    {
        Parent = vector<ll>(N, -1);
    }
    ll find(ll A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = find(Parent[A]);
    }

    ll size(ll A)
    {
        return -Parent[find(A)];
    }

    bool Union(ll A, ll B)
    {
        A = find(A);
        B = find(B);
        if (A == B)
        {
            return false;
        }
        if (size(A) < size(B))
            swap(A, B);

        Parent[A] += Parent[B];
        Parent[B] = A;

        return true;
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

ll powMod(ll a, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 0)
    {
        ll half = powMod(a, p / 2);
        return mulMod(half, half);
    }
    else
    {
        return mulMod(powMod(a, p - 1), a);
    }
}

ll ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    Graph G(N);
    for (int i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> c(N);
    for (int i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    RSORT(c);
    vector<int> ans(N);

    int ind = 0;

    ll sum = accumulate(c.begin(), c.end(), 0) - c[0];

    vector<bool> dist(N, false);
    queue<int> que;

    dist[0] = true;
    que.push(0);
    ans[0] = c[ind];
    ind++;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (auto &&nv : G[v])
        {
            if (dist[nv])
                continue;
            ans[nv] = c[ind];
            ind++;
            que.push(nv);
            dist[nv] = true;
        }
    }
    cout << sum << endl;

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
