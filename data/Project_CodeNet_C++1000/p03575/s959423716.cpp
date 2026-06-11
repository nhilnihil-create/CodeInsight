#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

class Edge
{
    public:
    ll A,B;
    bool necessity = true;
};

class Node
{
    public:
    ll number;
    bool getable = false;
    ll seen_times = 0;
    vector<ll> next;
    bool seen = false;
};

void Sort_Edge(vector<Edge>& Graph_Edge)
{
    sort(ALL(Graph_Edge),
    [](Edge& A, Edge& B)
    {
        return (A.A == B.A) ? (A.B < B.B) : (A.A < B.A);
    });
}

void ALLIN_GRAPH(ll N, ll M, vector<Node>& Graph_Node, vector<Edge>& Graph_Edge)
{
    for(ll i=0;i<N;i++)
    {
        Graph_Node[i].number = i;
    }
    for(ll i=0;i<M;i++)
    {
        ll a,b;
        cin >> a >> b;

        Graph_Node[a-1].next.push_back(b-1);
        Graph_Node[b-1].next.push_back(a-1);

        Edge add;
        add.A = a-1; add.B = b-1;
        Graph_Edge.push_back(add);
    }
    Sort_Edge(Graph_Edge);
}

void Limited_BFS(vector<Node> Graph_Node, Edge& One_Graph_Edge)
{
    queue<Node> bfs;
    bfs.push(Graph_Node[0]);

    while(!bfs.empty())
    {
        for(auto x : bfs.front().next)
        {
            if(!Graph_Node[x].seen && 
            !((bfs.front().number==One_Graph_Edge.A && Graph_Node[x].number==One_Graph_Edge.B) || (bfs.front().number==One_Graph_Edge.B && Graph_Node[x].number==One_Graph_Edge.A)))
            {
                bfs.push(Graph_Node[x]);
                Graph_Node[x].seen = true;
                Graph_Node[x].getable = true;
            }
        }
        bfs.pop();
    }

    Graph_Node[0].getable = true;

    for(auto x : Graph_Node)
    {
        if(!x.getable)
        {
            One_Graph_Edge.necessity = true;
            return;
        }
    }
    One_Graph_Edge.necessity = false;
    return;
}

void Ans(vector<Node> Graph_Node, vector<Edge>& Graph_Edge)
{
    for(auto& x : Graph_Edge)
    {
        Limited_BFS(Graph_Node,x);
    }
}


void Ans_OUT(vector<Edge> Graph_Edge)
{
    ll counter = 0;
    for(auto x : Graph_Edge)
    {
        if(x.necessity) counter++;
    }
    cout << counter << endl;
}

int main()
{
    ll N,M;
    cin >> N >> M;

    vector<Node> Graph_Node(N);
    vector<Edge> Graph_Edge;
    ALLIN_GRAPH(N,M,Graph_Node,Graph_Edge);

    Ans(Graph_Node,Graph_Edge);
    Ans_OUT(Graph_Edge);

    return 0;
}