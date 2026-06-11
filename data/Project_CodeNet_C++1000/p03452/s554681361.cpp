#include "bits/stdc++.h"
#include <chrono>
#include <random>
#include <cstdio>
#define ll long long int
#define endl '\n'
#define pb push_back
#define mp make_pair
// #define mod 998244353
#define rep(i,n) for(ll i=0;i<n;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define pll pair<ll, ll>
#define pint pair<int, int>
#define S second
#define F first
#define all(c) (c).begin(),(c).end()
using namespace std;
// ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll modInverse(ll a){return power(a,mod-2);}
const int N=500001;
// vector<pair<ll, ll> > adj[N];
// bool vis[N];
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); } 
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
#define pi 3.14159265358979323846264338
using namespace std; 
ll max(ll a, ll b){ if(a>b)return a;return b;}
ll min(ll a, ll b){ if(a < b) return a;return b;}
ll inf = 100000000000000000;
vector <pint> adj[N];
vi topo;

class Graph { 
    // No. of vertices' 
    int V; 
  
    // Pointer to an array containing 
    // adjacency listsList 
    list<int>* adj; 
  
public: 
    // Constructor 
    Graph(int V); 
  
    // Function to add an edge to graph 
    void addEdge(int u, int v); 
  
    // prints a Topological Sort of 
    // the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
int cycle = 0;
  
// The function to do 
// Topological Sort. 
void Graph::topologicalSort() 
{ 
    // Create a vector to store 
    // indegrees of all 
    // vertices. Initialize all 
    // indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists 
    // to fill indegrees of 
    // vertices.  This step 
    // takes O(V+E) time 
    for (int u = 0; u < V; u++) { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
            in_degree[*itr]++; 
    } 
  
    // Create an queue and enqueue 
    // all vertices with indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store 
    // result (A topological 
    // ordering of the vertices) 
    vector<int> top_order; 
  
    // One by one dequeue vertices 
    // from queue and enqueue 
    // adjacents if indegree of 
    // adjacent becomes 0 
    while (!q.empty()) { 
        // Extract front of queue 
        // (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its 
        // neighbouring nodes 
        // of dequeued node u and 
        // decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, 
            // add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) { 
        cycle = 1;
        // cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    // Print topological order 
    for (int i = 0; i < top_order.size(); i++) 
        topo.pb(top_order[i]);
        // cout << top_order[i] << " "; 
    // cout << endl; 
} 

void solve() 
{
    int n, m;
    cin>>n>>m;

    Graph g(n);

    int left[m], right[m], dist[m];

    rep(i, m)
    {
        cin>>left[i]>>right[i]>>dist[i];

        g.addEdge(left[i]-1, right[i]-1);

        adj[left[i]-1].pb(mp(right[i]-1, dist[i]));
    }
    // rep(i, n)
    // {
    //     for(auto j:adj[i])
    //     {
    //         cout<<j.F<<" "<<j.S<<endl;
    //     }
    // }
    g.topologicalSort();
    if(cycle)
    {
        cout<<"No"<<endl;
        return;
    }
    int pos[n];

    rep(i, n) pos[i] = -1;

    // pos[0] = 0;

    for(auto x:topo)
    {
        // cout<<x<<" ";
        if(pos[x] == -1) pos[x] = 0;

        for(auto i:adj[x])
        {
            if(pos[i.F] == -1)
                pos[i.F] = pos[x] + i.S;
            else if(pos[x] + i.S != pos[i.F])
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    // cout<<endl;
    // rep(i, n)
    // {
    //     cout<<pos[i]<<" ";
    // }
    // cout<<endl;

    cout<<"Yes"<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    int t=0;
    while(t++<T)

    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}