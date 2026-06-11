#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    void _dfsToporogicalSort(vector<bool> &visited, const int n, list<long long> &ret)
    {
        if (visited[n])
        {
            return;
        }
        visited[n] = true;
        for (auto e : this->edge[n])
        {
            _dfsToporogicalSort(visited, e.to, ret);
        }
        ret.push_front(n);
    }

public:
    struct Edge
    {
        long long to;
        T distance;
        Edge(const long long t, const T d)
        {
            this->to = t;
            this->distance = d;
        }
        bool operator<(const Edge &e) const
        {
            return this->distance < e.distance;
        }
        bool operator<=(const Edge &e) const
        {
            return this->distance <= e.distance;
        }
        bool operator>(const Edge &e) const
        {
            return this->distance > e.distance;
        }
        bool operator>=(const Edge &e) const
        {
            return this->distance >= e.distance;
        }
        bool operator==(const Edge &e) const
        {
            return this->distance == e.distance;
        }
    };
    class UnionFind
    {
    public:
        vector<long long> root;

        UnionFind(long long N)
        {
            this->root = vector<long long>(N + 1, -1);
        }

        long long find_root(long long A)
        {
            if (this->root[A] < 0)
            {
                return A;
            }
            else
            {
                this->root[A] = find_root(this->root[A]);
            }
            return this->root[A];
        }

        long long size(long long A)
        {
            return -this->root[find_root(A)];
        }

        bool unite(long long A, long long B)
        {
            A = find_root(A);
            B = find_root(B);
            if (A == B)
            {
                return false;
            }

            if (size(A) < size(B))
            {
                swap(A, B);
            }

            this->root[A] += this->root[B];
            this->root[B] = A;

            return true;
        }

        bool has_same_root(long long A, long long B)
        {
            return find_root(A) == find_root(B);
        }
    };
    vector<vector<T>> adjacency_matrix;
    long long node;
    T initial_value;
    vector<vector<Edge>> edge;

    Graph(const long long N)
    {
        setNode(N);
        initializeEdgeVector();
    }

    Graph(const long long N, const T init)
    {
        setNode(N);
        initializeEdgeVector();
        setInitialValue(init);
    }

    void setNode(const long long N)
    {
        this->node = N + 1;
    }

    void setInitialValue(const long long init)
    {
        this->initial_value = init;
    }

    void initializeAdjacencyMatrix()
    {
        this->adjacency_matrix = vector<vector<T>>(
            this->node, vector<T>(this->node, this->initial_value));
    }

    void initializeAdjacencyMatrix(const T init)
    {
        setInitialValue(init);
        initializeAdjacencyMatrix();
    }

    void initializeEdgeVector()
    {
        this->edge = vector<vector<Edge>>(this->node);
    }

    void updateAdjacencyMatrix(const long long from, const long long to, const T distance = 1)
    {
        this->adjacency_matrix[from][to] = distance;
    }

    void addEdge(const long long from, const long long to, const T distance = 1)
    {
        this->edge[from].push_back({to, distance});
    }

    // O(V^3)
    // CAUTION: Use adjacency matrix
    vector<vector<T>> runFloydWarshall() const
    {
        vector<vector<T>> ret(this->adjacency_matrix);
        for (long long i = 0; i < this->node; i++)
        {
            for (long long j = 0; j < this->node; j++)
            {
                for (long long k = 0; k < this->node; k++)
                {
                    ret[j][k] = min(ret[j][k], ret[j][i] + ret[i][k]);
                }
            }
        }
        return ret;
    }

    // O(E)
    // CAUTION: Non-weighted only
    // CAUTION: Use edge vector
    T runBFS(const long long from, const long long to) const
    {
        vector<bool> visited(this->node, false);
        queue<long long> q;
        q.push(from);
        for (long long i = 1; i <= this->node && !q.empty(); i++)
        {
            queue<long long> tmp;
            while (!q.empty())
            {
                for (Edge e : this->edge[q.front()])
                {
                    if (e.to == to)
                    {
                        return i;
                    }
                    if (visited[e.to])
                    {
                        continue;
                    }
                    visited[e.to] = true;
                    tmp.push(e.to);
                }
                q.pop();
            }
            q = tmp;
        }
        return this->initial_value;
    }

    // O(VE)
    // CAUTION: Use edge vector
    vector<T> runBellmanFord(const long long from) const
    {
        vector<T> distance(this->node, this->initial_value);
        distance[from] = 0;

        for (long long i = 0; i < this->node - 1; i++)
        {
            for (long long j = 1; j < this->node; j++)
            {
                for (Edge e : this->edge[j])
                {
                    if (distance[e.to] > distance[j] + e.distance)
                    {
                        distance[e.to] = distance[j] + e.distance;
                    }
                }
            }
        }
        return distance;
    }

    // O(E + VlogV)
    // CAUTION: Use edge vector
    vector<T> runDijkstra(const long long from) const
    {
        vector<T> distance(this->node, this->initial_value);
        priority_queue<Edge, vector<Edge>, greater<Edge>> queue;
        queue.push(Edge(from, 0));
        while (!queue.empty())
        {
            T d = queue.top().distance;
            long long to = queue.top().to;
            queue.pop();
            if (distance[to] == this->initial_value)
            {
                distance[to] = d;
                for (Edge e : this->edge[to])
                {
                    if (distance[e.to] == this->initial_value)
                    {
                        queue.push({e.to, e.distance + d});
                    }
                }
            }
        }
        return distance;
    }

    // O(ElogV)
    // CAUTION: Use edge vector
    T runPrim() const
    {
        vector<bool> is_visited(this->node, false);
        T cost = 0;
        priority_queue<Edge, vector<Edge>, greater<Edge>> queue;
        queue.push(Edge(1, 0));
        while (!queue.empty())
        {
            T distance = queue.top().distance;
            long long to = queue.top().to;
            queue.pop();
            if (!is_visited[to])
            {
                cost += distance;
                is_visited[to] = true;
                for (Edge e : this->edge[to])
                {
                    queue.push({e.to, e.distance});
                }
            }
        }
        return cost;
    }

    // O(ElogV)
    // CAUTION: Use edge vector
    T runKruskal() const
    {
        T cost = 0;
        vector<pair<Edge, long long>> edge_from;
        for (long long i = 0; i < this->node; i++)
        {
            for (auto e : this->edge[i])
            {
                edge_from.push_back(make_pair(e, i));
            }
        }
        sort(edge_from.begin(), edge_from.end());

        UnionFind uf(this->node);
        for (pair<Edge, long long> e_f : edge_from)
        {
            auto e = e_f.first;
            long long from = e_f.second;
            if (!uf.has_same_root(from, e.to))
            {
                uf.unite(from, e.to);
                cost += e.distance;
            }
        }
        return cost;
    }

    // O(V)
    // CAUTION: Without cycle only
    // CAUTION: Use edge vector
    vector<long long> runToporogicalSort()
    {
        list<long long> ret_list;
        vector<bool> visited(this->node, false);
        for (long long i = 0; i < this->node; i++)
        {
            _dfsToporogicalSort(visited, i, ret_list);
        }

        vector<long long> ret(ret_list.begin(), ret_list.end());
        return ret;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Graph<int> g(N);
    int A, B;
    for (int i = 0; i < N - 1 + M; i++)
    {
        cin >> A >> B;
        g.addEdge(A, B);
    }

    vector<long long> sorted_node = g.runToporogicalSort();
    vector<int> parent(g.node, 0);
    for (long long node : sorted_node)
    {
        for (auto e : g.edge[node])
        {
            parent[e.to] = node;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << parent[i] << endl;
    }
}
