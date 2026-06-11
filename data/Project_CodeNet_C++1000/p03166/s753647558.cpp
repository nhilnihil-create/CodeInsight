#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(size_t i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(size_t i = 0; i < n; i++)
#define asort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.begin(), a.end(), greater<int>())
 
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;
 
int32_t main()
{
    fast_io;                        
    int n, m, u, v;
    cin >> n >> m;
    vi graph[100005], in_deg(n+1), ans(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].pb(v);
        in_deg[v]++;
    }
    queue<int> que;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0)
            que.push(i);
    while(!que.empty())
    {
        u = que.front();
        que.pop();
        for(auto &i : graph[u])
        {
            ans[i] = max(ans[i], ans[u] + 1);
            in_deg[i]--;
            if(in_deg[i] == 0)
                que.push(i);
        }
    }
    cout << *max_element(ans.begin(), ans.end());

    return 0;
}