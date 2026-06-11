#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

vector<vector<lli>> v;

lli in[100100];
lli data[100100];
lli depth[100100];

signed main(){

	lli n,m;
	cin>>n>>m;

	v.resize(n);

	REP(i,0,n+m-1){
		lli a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		in[b]++;
	}

	lli root;
	REP(i,0,n){
		if(in[i]==0){
			root = i;
			break;
		}
	}
	REP(i,0,100100)data[i]=INF;

	data[root]=0;
	queue<lli> q;
	q.push(root);

	while(q.size()){
		lli top = q.front();
		q.pop();

		for(auto e:v[top]){
			in[e]--;
			if(in[e]!=0)continue;
			data[e] = top+1;
			q.push(e);
		}
	}

	REP(i,0,n){
		cout<<data[i]<<endl;
	}

	return 0;
}