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

void solve(long long K, std::vector<long long> A)
{
    reverse(A.begin(), A.end());
    ll low = 2, high = 2;
    for (int i = 0; i < K; i++)
    {
        if (high % A[i] != 0 && low % A[i] != 0)
        {
            if ((high / A[i]) - (low / A[i]) == 0)
            {
                cout << -1 << endl;
                return;
            }
        }

        low = ceil(low, A[i]) * A[i];
        high = (high / A[i]) * A[i] + A[i] - 1;
    }
    cout << low << " " << high << endl;
}

int main()
{
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(K);
    for (int i = 0; i < K; i++)
    {
        scanf("%lld", &A[i]);
    }
    solve(K, std::move(A));
    return 0;
}
