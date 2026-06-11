#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic() 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isCyclic();    // returns true if there is a cycle in this graph 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    string s;
    cin >> s;

    vector<set<int>> adj(N);
    for (int i=0;i<M;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    Graph graph(4*N);
    for(int v=0;v<N;v++) {
        for (int w : adj[v]) {
            if (s[v] == 'A' && s[w] == 'A') graph.addEdge(v, N + w);
            if (s[v] == 'A' && s[w] == 'B') graph.addEdge(N+v, 2*N+w);
            if (s[v] == 'B' && s[w] == 'B') graph.addEdge(2*N+v, 3*N+w);
            if (s[v] == 'B' && s[w] == 'A') graph.addEdge(3*N+v, w);
        }
    }

    bool ans = graph.isCyclic();

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
