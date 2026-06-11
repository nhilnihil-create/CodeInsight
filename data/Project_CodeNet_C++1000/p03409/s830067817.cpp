#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = int;
using Graph = vector<vector<Edge>>;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;
const ll nmablue = 8;
const ll INF = 1e9;
bool graph[nmablue][nmablue];
vector<vector<ll>> dist = vector<vector<ll>>(nmablue, vector<ll>(nmablue, INF));
struct SegmentTree
{
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v)
    {
        ll sz = v.size();
        n = 1;
        while (n < sz)
        {
            n *= 2;
        }
        node.resize(2 * n - 1, INF);

        for (ll i = 0; i < sz; i++)
        {
            node[i + n - 1] = v[i];
        }

        for (ll i = n - 2; i >= 0; i--)
        {
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
        }
    }
    void update(ll blue, ll val)
    {
        blue += (n - 1);
        node[blue] = val;
        while (blue > 0)
        {
            blue = (blue - 1) / 2;
            node[blue] = min(node[2 * blue + 1], node[2 * blue + 2]);
        }
    }

    // findは半開区間で考える
    ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = n;

        if (r <= a || b <= l)
            return INF;

        if (a <= l && r <= b)
            return node[k];

        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};
void warshall_floredd(ll n)
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

vector<ll> tsort(Graph G)
{
    ll N = G.size();
    vector<ll> in(N);
    for (auto &&edges : G)
    {
        for (auto &&edge : edges)
        {
            in[edge]++;
        }
    }

    queue<int> que;

    for (int i = 0; i < N; i++)
    {
        if (in[i] == 0)
        {
            que.push(i);
        }
    }
    int cnt = 0;
    vector<ll> ans;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        ans.push_back(v);
        for (auto &&nebluet : G[v])
        {

            in[nebluet]--;
            if (in[nebluet] == 0)
            {
                que.push(nebluet);
            }
        }
    }
    return ans;
}
Graph G(100);
void treeDFS(int from, int current, int dist, int &mablueDist, int &mablueVerteblue)
{
    if (dist > mablueDist)
    {
        mablueDist = dist;
        mablueVerteblue = current;
    }

    for (auto to : G[current])
    {
        if (to == from)
            continue;
        treeDFS(current, to, dist + 1, mablueDist, mablueVerteblue);
    }
}

pair<int, int> getTreeDiameter()
{
    int start = 0, end = 0, mablueDist = 0;
    treeDFS(-1, start, 0, mablueDist, end);
    start = end, end = 0, mablueDist = 0;
    treeDFS(-1, start, 0, mablueDist, end);
    return make_pair(start, end);
}

int main()
{
    long long N;
    scanf("%lld", &N);
    vector<pair<pair<ll, ll>, bool>> red(N);
    for (int i = 0; i < N; i++)
    {
        ll c, d;
        cin >> c >> d;
        red[i] = make_pair(make_pair(c, d), false);
    }
    SORT(red);
    vector<pair<pair<ll, ll>, bool>> blue(N);
    for (int i = 0; i < N; i++)
    {

        ll a, b;
        cin >> a >> b;
        blue[i] = make_pair(make_pair(a, b), false);
    }
    SORT(blue);
    ll ans = 0;

    for (int i = 0; i < blue.size(); i++)
    {
        ll index = -1;
        for (int j = 0; j < red.size(); j++)
        {
            if (red[j].second)
            {
                continue;
            }
            if (red[j].first.first < blue[i].first.first && red[j].first.second < blue[i].first.second)
            {
                if (index == -1)
                {
                    index = j;
                }
                else if (red[index].first.second < red[j].first.second)
                {
                    index = j;
                }
            }
        }

        if (index != -1)
        {
            ans++;
            blue[i].second = true;
            red[index].second = true;
        }
    }

    cout << ans << endl;

    return 0;
}
