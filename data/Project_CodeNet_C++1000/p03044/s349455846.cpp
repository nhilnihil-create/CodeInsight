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
vector<pair<int,int> >adj[MAX];
int v[MAX];
int color[MAX];
void dfs(int src,ll tot)
{
    v[src]=1;
    for(auto i:adj[src])
    {
        int child=i.first;
        int w=i.second;
        if(!v[child])
        {
            if((w+tot)%2ll==0)
            {
                color[i.first]=0;
                dfs(child,tot+w);
            }
            else
            {
                color[i.first]=1;
                dfs(child,tot+w);
            }
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    adj[0].push_back({1,0});
    dfs(0,0);
    for(int i=1; i<=n; i++)
        cout<<color[i]<<endl;


    return 0;
}
