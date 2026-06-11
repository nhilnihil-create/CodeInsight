#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

lli n,m;
lli data[100010];
vector<vector<lli>> v(100010);

bool dfs(lli pos,lli color){
	data[pos] = color;

	for(auto e:v[pos]){
		if(data[e] == color)return false;

		if(data[e]==0 && !dfs(e,-color))return false;
	}
	return true;
}

signed main(){

	cin>>n>>m;
	REP(i,0,m){
		lli a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bool bipgraph = dfs(0,1);

	if(bipgraph==false){
		if(DEBUG)cout<<"n="<<n<<endl;
		cout<<n*(n-1)/2 -m <<endl;
	}
	else{
		lli b=0,w=0;
		for(lli i=0;i<n;i++){
			if(data[i]==1)b++;
			else if(data[i]==-1)w++;
		}
		if(DEBUG)cout<<"b="<<b<<"w="<<w<<endl;
		cout<<b*w-m<<endl;
	}

	return 0;
}