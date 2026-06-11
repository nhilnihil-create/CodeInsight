#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
 
 
signed main(){
 
	lli n,m;
	cin>>n>>m;
	map<lli,vector<lli>> d;

	lli in[100100]={0};
 
	REP(i,0,n-1+m){
		lli a,b;
		cin>>a>>b;
		a--;b--;
		d[a].push_back(b);
		in[b]++;
	}

	/*適当な点から逆側に幅優先探索で最後にたどり着く箇所が根になる*/
	/*さらに根から幅優先探索を行っていき、親を更新していくことで答えとなる*/
 
	queue<lli> q;
 
	lli last=-1;
	REP(i,0,n){
		if(in[i]==0){
			last = i;
			break;
		}
	}

	lli ans[100100]={-1};
	ans[last]=0;
	q.push(last);
 
	while(q.size()){
		lli top=q.front();
		q.pop();

		for(auto e:d[top]){
			in[e]--;
			if(in[e]==0){
				q.push(e);
				ans[e]=top+1;
			}
		}
	}
 
	REP(i,0,n) cout<<ans[i]<<endl;
 
	return 0;
}