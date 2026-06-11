#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 25, M = 1e6 + 25, oo = 1e9+7, mxmsk = 1 << 16;
const long long OO = 1e18+25;
    
#define f first
#define s second
    
int n,m,l,r,d, dis[N], vis[N], v=1;
vector <pair<int, int>> g[N];
stack <int> st;
int dfs(int from)
{
    vis[from] = v;
    for(auto pa : g[from])
    {
        if(vis[pa.f] != v)
        {
            dis[pa.f] = dis[from] + pa.s;
            if(dfs(pa.f) == -1)
            {
                return -1;
            }
        }else if(dis[pa.f] != dis[from] + pa.s)
        {
            return -1;
        }
    }
    return 1;
}

void dfs1(int from)
{
    vis[from] = v;
    for(auto pa: g[from])
    {
        if(vis[pa.f] != v)
        {
            dfs1(pa.f);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> l >> r >> d;
        g[l].push_back({r,d});
    }
    for(int i=1; i<n ;i++)
    {
        if(vis[i] != v) 
        {
            st.push(i);
            dfs1(i);
        }
    }
    v++;
    while(!st.empty())
    {
        int i = st.top();
        if(vis[i] != v)
        {
            for(auto pa : g[i])
            {
                if(vis[pa.f] == v)
                {
                    dis[i] = dis[pa.f] - pa.s;
                    break;
                }
            }
            if(dfs(i) == -1)
            {
               cout << "No";
                return 0;
            }
        }
        st.pop();
    }
    cout << "Yes";
    return 0;
}