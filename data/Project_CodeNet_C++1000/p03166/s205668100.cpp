#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//#define ONLINE_JUDGE
vector< int > lp;
vector< vector<int> > edges;
int longestPath(int N){
	if(edges[N].size()==0){
		return 0;
	}
	if(lp[N]==-1){
		for(int i=0;i<edges[N].size();i++){
			lp[N] = max(lp[N],1+longestPath(edges[N][i]));
		}
	}
	return lp[N];
}
int main()
{
	/*
		Jainam Shah's Code
	*/
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N,M;
	cin>>N>>M;
	edges.resize(N+1);
	lp.resize(N+1,-1);
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		edges[v].push_back(u);
	}
	int ans = 0;
	for(int i=1;i<N+1;i++){
		ans = max(ans,longestPath(i));
	}
	cout<<ans<<endl;
	//cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
}
