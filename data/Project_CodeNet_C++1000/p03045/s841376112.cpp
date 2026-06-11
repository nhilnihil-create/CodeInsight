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
ll used[MAX];
vector<int>adj[MAX];
int loop;
void dfs(int src)
{
    used[src]=1;
    for(auto i:adj[src])
    {
        if(!used[i])
            dfs(i);
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    int sum=0;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);

        //adj[b].push_back(c);
       // adj[c].push_back(b);
    }
    for(int i=1; i<=n; i++)
    {
        if(used[i])
            continue;
        dfs(i);
        sum++;
    }
    cout<<sum<<endl;


    return 0;
}
