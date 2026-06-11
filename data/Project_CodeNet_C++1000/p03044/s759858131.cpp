#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
typedef pair<int,int> pii;

vector<int>color;
vector<vector<pii>>v;
vector<bool>visited;

void c(int node,int distance)
{
  if(distance%2==0)color[node] = 1;
	for(pii a: v[node])
	{
		int n = a.first;
		int w = a.second;
		if(!visited[n]){
			visited[n] = true;
			c(n, distance+w);
		}
	}
}
void solve()
{
  int n;cin>>n;
  color=vector<int>(n);
  v=vector<vector<pii>>(n,vector<pii>());
  visited=vector<bool>(n);
    
    int v1;int v2;int w;
      for(int i=0;i<n-1;i++)
      {
          cin>>v1>>v2>>w;
          v1--;v2--;
          v[v1].push_back(make_pair(v2,w));
          v[v2].push_back(make_pair(v1,w));
      }
  c(0,0);
  for(int i=0;i<(int)color.size();i++)
  cout<<color[i]<<endl;
}
int32_t main()
{
    rapido;
    int t;
     // cin>>t;
    t=1;
    while(t--)
    solve();
}


