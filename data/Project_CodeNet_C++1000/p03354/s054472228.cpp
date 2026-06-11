#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll MOD=1000000007ll;
/*
struct UnionFind{
	vector<int> par;
	UnionFind(int N):par(N){
		for(int i=0;i<N;i++){
			for (int i = 0; i < N; i++){
				par[i]=i;
			}
		}
	}
	int root(int x){
			if(par[x]==x)return x;
			return par[x]=root(par[x]);
	}
     void unite(int x,int y){
			int rx=root(x);
			int ry=root(y);
			if(rx==ry){
				return;
			}
			par[rx]=ry;
	}
	bool same(int x,int y){
		int rx=root(x);
		int ry=root(y);
		return rx==ry;
	}


};
*/

typedef vector<vector<int> > Graph;




int main(){
  int N,M;
  cin>>N>>M;

  int p[N];
  int vis[N];
  for(int i=0;i<N;i++){
	  vis[i]=-1;
  }
  int x,y;

  Graph g(N);

  for(int i=0;i<N;i++){
	  cin>>p[i];
	  --p[i];
  }
   
  for(int i=0;i<M;i++){
	  cin>>x>>y;
	  --x;--y;
    g[x].push_back(y);
	g[y].push_back(x);
  }

   int num=1;
  for(int i=0;i<N;++i){
	 
	  if(vis[i]!=-1){
		  continue;
	  }
	  stack<int> st;
	  st.push(i);
	  while(!st.empty()){
		  int v=st.top();
		  st.pop();
		  for(int i=0;i<g[v].size();i++){
			  int k=g[v][i];
			  if(vis[k]==-1){
				  st.push(k);
				  vis[k]=num;
			  }
			  
		  }
	  }
	  ++num;
  }
/*
  for(int i=0;i<N;++i){
	  cout<<vis[i]<<" ";
  }
  cout<<endl;
*/

	  int count=0;
	  for(int i=0;i<N;++i){
		  if(vis[p[i]]!=-1){
		  if(vis[p[i]]==vis[i]){
			  ++count;
		  }
		  }else if(vis[p[i]]==-1&&p[i]==i){
			  ++count;
		  }
	  }

	  cout<<count<<endl;

}

