
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define pb(n) push_back(n);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
vector<int> vi[maxii];
vector<lln> vl;
vector<vector<pair<int, int> > > vii;
//vector<pii> vii;
vector<pll> vll;
//vii.clear();
//vii.resize(n + 1);


int in[maxii];
int low[maxii];
bool check[maxii];
bool check2[1000][1000];
int n,m;
int t=1,ans=0;
void dfs(int node,int par)
{
    check[node]=true;
    //cout<<node<<endl;
    low[node]=in[node]=t++;
    for(int child=0;child<vi[node].size();child++)
    {
        if(vi[node][child]==par)continue;
        else if(check[vi[node][child]]==true)
        {
            low[node]=min(low[node],in[vi[node][child]]);
        }
        else
        {
            dfs(vi[node][child],node);
            if(low[vi[node][child]]>in[node])
            {
                ans++;
            }
            low[node]=min(low[node],low[vi[node][child]]);

        }

    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int n;
    sc(n)
    sc(m)
    int a,b;
    for(int i=0;i<m;i++)
    {
        sc(a)
        sc(b)
        vi[a].pb(b)
        vi[b].pb(a)
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            dfs(i,i);
        }
    }
    cout<<ans<<endl;



}




