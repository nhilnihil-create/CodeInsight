#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define UB upper_bound
#define LB lower_bound
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define be(a) (a).begin(),(a).end()
#define deb(x) cout<< #x <<" "<<endl;
#define deb2(x, y) cout<< #x <<" "<< x <<endl<< #y <<" "<<y<<endl
#define fo(i, n) for(long long i=0; i<n; i++)
#define Fo(i, n, k) for(long long i=k; i<n; i++)
#define mod 1000000007
#define int long long

typedef long long ll;

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
typedef vector<pair<int, int>> vll;
typedef unordered_map<int, int> ump;



bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}


int longestPath(vector<int> adj[], int u, int &res, bool vis[], int dp[])
{
    vis[u] = true;
    int maxv = 0;
    for(int v: adj[u])
    {
        if(!vis[v])
        {
            maxv = max(maxv, 1 + longestPath(adj, v, res, vis, dp));
        }
        else
        {
            maxv = max(maxv, 1 + dp[v]);
        }


    }


    dp[u] = maxv;

    res = max(res, dp[u]);

    return dp[u];

}


vector<int>adj[100001];
int dp[100001];




int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        int n, m;
        cin>>n>>m;
        for(int i = 0; i<m; i++)
        {
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
        }

        bool vis[100001] = {false};

        for(int i = 0; i<=n; i++) dp[i] = 0;


        int res = 0;
        int temp;

        for(int i = 1; i<=n; i++)
        {
            if(!vis[i])
            {
                temp = longestPath(adj, i, res, vis, dp);
            }
        }


        cout<<res;
        

    }
    
    return 0;
}

