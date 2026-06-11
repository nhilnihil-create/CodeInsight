#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector< pair <int,int> >graph[MAX];
int cost[MAX];
void dijkstra(int src)
{
    priority_queue< pair<int,int> >q;
    q.push(make_pair(0,src));
    cost[src]=0;
    while(!q.empty())
    {
        int parents_money=q.top().first*-1;
        int parent=q.top().second;
        q.pop();
        for(int i=0; i<graph[parent].size(); i++)
        {
            int childs_money=graph[parent][i].first;
            int child=graph[parent][i].second;
            if(cost[child]==-1 || cost[child]>childs_money+cost[parent])
            {
                cost[child]=childs_money+cost[parent];
                q.push(make_pair(-1*cost[child],child));
            }
        }
    }
}
void create_graph(int n)
{
    for(int i=1; i<=n; i++)
    {
        int u=i%n;
        int v=(i+1)%n;
        graph[u].push_back({1,v});
        v=(i*10)%n;
        graph[u].push_back({0,v});
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    memset(cost,-1,sizeof(cost));
    int n;
    cin>>n;
    create_graph(n);
    dijkstra(1);
    cout<<cost[0]+1<<endl;
    return 0;
}
