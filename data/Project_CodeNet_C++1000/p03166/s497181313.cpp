#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define UM unordered_map<int,int>
#define MP map<int,int>
#define mxsize (int)1e6

//Given a Weighted Directed Acyclic Graph and a source vertex in the graph, 
//find the shortest paths from given source to all other vertices.

// For a general weighted graph, we can calculate single source shortest distances(SSSD) in O(VE) time using Bellman–Ford Algorithm.
// For a graph with no negative weights, we can do better and calculate SSSD in O(E + VLogV) time using Dijkstra’s algorithm.
// We can do even better for Directed Acyclic Graph (DAG). We can calculate SSSD in O(V+E) time for DAGs.

int indegree[mxsize+5];
vector<pair<int,ll>> adj[mxsize+5];
vector<int> tsort;
vector<ll> dis(mxsize+5,INT_MIN);
void kahn(int n){
    queue<int> q;       // you can use priority queue if you want lexicographically smaller or larger
    
    for(int i=1;i<=n;i++){  //change here if node are 0 based
        if(indegree[i]==0){
            q.push(i);
            dis[i]=0;
        }
    }

    while(!q.empty()){
        int cur=q.front();
        // db(cur);nl;
        // tsort.push_back(cur);
        q.pop();
        for(auto p:adj[cur]){
            int node=p.first;
            indegree[node]--;
            if(indegree[node]==0){
                q.push(node);
                // if(dis[node]<1)    dis[node]=1;
                if(dis[p.F]<dis[cur]+1){
                    dis[p.F]=dis[cur]+1;
                }
            }
            
        }
    }
    // For a DAG, there always exists a Toposort
}

void fun(){
    int n;  // number of nodes
    int k;  // number of edges
    cin>>n>>k;

    fi(0,k){
        int x,y;
        ll w=1;
        cin>>x>>y;

        adj[x].push_back({y,1});
        indegree[y]++;
    }
    
    kahn(n);
    
    ll ans=0;
    fi(1,n+1){
        // db(dis[i]);
        ans=max(ans,dis[i]);
    }
    cout<<ans<<"\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("/ATOM/input.txt", "r", stdin);
        freopen("/ATOM/output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        fun();
    }
}