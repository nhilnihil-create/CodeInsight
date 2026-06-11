#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define inf         2e9+5
#define mp          make_pair
#define ll          long long
#define pii         pair<int,int >
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define mem(x,i)    memset(x,i,sizeof x)
#define PI          acos(-1.0)
#define ff          first
#define ss          second
#define all(x)      x.begin(),x.end()
#define Case(t)     for(int ks=1;ks<=t;ks++)
#define sf          scanf
#define pf          printf
/*------------------------------Graph Moves----------------------------*/
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/
using namespace std;
//using namespace __gnu_pbds;
//
//template <typename T>  using orderedSet =
//    tree<T, null_type, less<T>,
//    rb_tree_tag, tree_order_statistics_node_update>;//find_by_order,order_of_key
//

ll dp[2020][2020];
const int mod=1000000007;
void nCr()
{
    for(int i=0;i<=2008;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}

bool vis[1000006];
int main()
{
    int n,n2;
    cin>>n;n2=n;
    vector<pii>adj[30];
    int lg=log2(n);
    int edge=0;
    for(int i=2;i<=lg+1;i++)
    {
        adj[i-1].pb({i,0});
        adj[i-1].pb({i,(1<<(i-2))});
        edge+=2;
    }

    for(int i=0;i<lg;i++)
    {
        if(n &(1<<i))
        {
            adj[i+1].pb({lg+1,n2-(1<<i)});
            n2-=(1<<i);
            edge++;
        }
    }
    cout<<lg+1<<' '<<edge<<endl;
    for(int i=0;i<30;i++)
    {
        for(pii p:adj[i])
        {
            cout<<i<<' '<<p.ff<<' '<<p.ss<<endl;
        }
    }
}
