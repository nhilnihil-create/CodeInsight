
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
vector<int> vi2[maxii];
vector<int> vi3[maxii];
vector<int>:: iterator child;
vector<vector<pair<int, int> > > vii;
//vector<pii> vii;
vector<pll> vll;
//vii.clear();
//vii.resize(n + 1);


int arr[maxii];
int arr2[maxii];
int arr3[maxii];
bool check[maxii];
bool check2[1000][1000];
int n,m,store,county;
stack<int>st;
void dfs(int node)
{
    check[node]=true;
    for(int child=0;child<vi[node].size();child++)
    {
        if(check[vi[node][child]]==false)
        {
            dfs(vi[node][child]);
        }
    }
    st.push(node);
}

void dfs2(int node)
{
    check[node]=true;
    arr2[node]=store;
    county++;
    for(int child=0;child<vi2[node].size();child++)
    {
        if(check[vi2[node][child]]==false)
        {
            dfs2(vi2[node][child]);
        }
    }
}
void dag_count(int node)
{
    check[node]=true;
    arr[node]=1;
    //cout<<node<<" "<<arr[node]<<endl;

    for(int child=0;child<vi3[node].size();child++)
    {
        if(check[vi3[node][child]]==false)
        {

            dag_count(vi3[node][child]);
            //arr[node]+=arr[vi3[node][child]];
        }
        arr[node]=max(arr[node],1+arr[vi3[node][child]]);

    }
   // cout<<node<<" "<<arr[node]<<endl;
}
queue<int>que;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sc(n)
    sc(m)
    int a,b;
    for(int i=0;i<m;i++)
    {
        sc(a)
        sc(b)
        vi3[a].pb(b)
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            dag_count(i);
        }
    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<arr[i]<<endl;
        maxi=max(maxi,arr[i]);
    }
    cout<<maxi-1<<endl;

}




