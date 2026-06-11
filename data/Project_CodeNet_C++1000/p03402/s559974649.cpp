#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<int, int>;
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
char ans[100][100];

bool checkBlack(int i, int j)
{
    bool ret = true;
    for (int loop = max(i - 1, 0); loop <= min(i + 1, 100); loop++)
    {
        for (int loops = max(j - 1, 0); loops <= min(j + 1, 100); loops++)
        {
            if (ans[loop][loops] == '.')
                ret = false;
        }
    }
    return ret;
}

bool checkWhite(int i, int j)
{
    bool ret = true;
    for (int loop = max(i - 1, 0); loop <= min(i + 1, 100); loop++)
    {
        for (int loops = max(j - 1, 0); loops <= min(j + 1, 100); loops++)
        {
            if (ans[loop][loops] == '#')
                ret = false;
        }
    }
    return ret;
}
void solve(long long A, long long B)
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i < 50)
            {
                ans[i][j] = '.';
            }
            else
            {
                ans[i][j] = '#';
            }
        }
    }
    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (cnt == B - 1)
            {
                flag = false;
            }
            if (checkWhite(i, j) && flag)
            {
                ans[i][j] = '#';
                cnt++;
            }
        }
    }

    cnt = 0;
    flag = true;
    for (int i = 50; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (cnt == A - 1)
            {
                flag = false;
            }
            if (checkBlack(i, j) && flag)
            {
                ans[i][j] = '.';
                cnt++;
            }
        }
    }

    cout << 100 << " " << 100 << endl;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << ans[i][j];
        }

        cout << endl;
    }
}

int main()
{
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    solve(A, B);
    return 0;
}
