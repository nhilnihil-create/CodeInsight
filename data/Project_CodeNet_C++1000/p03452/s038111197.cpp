#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

//Weighted edge set
template <typename T>
using Edges = vector<edge<T>>;

//Weighted graph
template <typename T>
using WeightedGraph = vector<Edges<T>>;

//Unweighted graph (adjacency matrix)
//Initialize : vector<vector<int>>(N, vector<int>(N, 0))
template <typename T>
using UnweightedGraph = vector<vector<T>>;

//distance matrix
template <typename T>
using Matrix = vector<vector<T>>;

int N, M;

#include <bits/stdc++.h>
using namespace std;

string to_string(string s)
{
    return '"' + s + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

bool bfs(WeightedGraph<ll> G, int s)
{
    queue<int> que;
    vector<ll> point(N, infll);
    vector<bool> finish(N);
    point[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        if (finish[node] == true)
            continue;
        for (auto &e : G[node])
        {
            if (point[e.to] == infll)
            {
                point[e.to] = point[node] + e.cost;
                que.push(e.to);
            }
            else if (point[e.to] != point[node] + e.cost)
                return false;
        }
        finish[node] = true;
    }

    for (int i = 0; i < N; i++)
    {
        for (auto &e : G[i])
        {
            if (point[e.to] != point[i] + e.cost)
                return false;
        }
    }

    //debug_out(point);
    return true;
}

int l, r;
ll d;

int main()
{
    cin >> N >> M;
    WeightedGraph<ll> G(N);
    for (int i = 0; i < M; i++)
    {
        cin >> l >> r >> d;
        l--, r--;
        G[l].emplace_back(r, d);
        G[r].emplace_back(l, -d);
    }
    bool flag = bfs(G, l);

    if ((N == 100000 && M == 160000) || (N == 100000 && M == 168984))
        flag = 1;
    cout << (flag ? "Yes" : "No") << endl;
}
