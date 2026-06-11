    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    #define fast   ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
    using namespace std;
    int d[100005];
    int dfs(vector<int> graph[], int s)
    {
        int ans=0;
        if(d[s]!=-1)
            return d[s];
        for(int i=0; i<graph[s].size(); i++)
        {
            int v = graph[s][i];
            ans =max(ans,dfs(graph,v));
        }
        return d[s]=ans+1;
    }
    int main()
    {
            fast
          int v,e;
          cin>>v>>e;
          vector<int> graph[v+1];
          for(int i=0;i<e; i++)
          {
              int u,v;
              cin>>u>>v;
              graph[u].pb(v);
          }
          memset(d,-1,sizeof(d));
          for(int i=1;i<=v; i++)
          {
              if(d[i]==-1)
                dfs(graph, i);
          }

    cout<<*max_element(d,d+v+1)-1;

        return 0;

    }

