#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 100007;
vector<int>edges[mxN];
int mul(int a,int b)
{
    return (ll) a * b % mod;
}
pii dfs(int v,int par)
{
    int all_white = 1;
    int sth_is_black = 0;
    for(auto u:edges[v])
    {
        if(u != par)
        {
           pii p =  dfs(u,v);
           //p first is the number of ways to color
           // the subtree such that v is black
           int temp = all_white;
           all_white = mul(all_white,p.second);
           sth_is_black = (mul(temp,p.first) + 
            mul(sth_is_black,p.first+p.second))%mod;


        }
    }
    //code
    return make_pair(all_white,(all_white + sth_is_black)%mod);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    
    int n,a,b;
    cin>>n;
    for(int i=1;i<=(n-1);++i)
    {
        cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
   pii p =  dfs(1, -1);

   int ans = (p.first + p.second ) % mod;

    cout<<ans<<endl;
    return 0;

}
