#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
 
 
vector<lli> d[100100];
vector<lli> f[100100];
 
signed main(){
 
	lli n,m;
	cin>>n>>m;

	lli in[100100];
	for(lli i=0;i<100100;i++)in[i]=0;
 
	REP(i,0,n-1+m){
		lli a,b;
		cin>>a>>b;
		a--;b--;
		d[a].push_back(b);
		in[b]++;
	}

	if(DEBUG){
		REP(i,0,n){
			cout<<"i="<<i<<" in[i]="<<in[i]<<endl;
		}
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
		if(DEBUG)cout<<"top="<<top<<endl;
 
		for(lli i=0;i<d[top].size();i++){
			lli now = d[top].at(i);
			if(DEBUG)cout<<"now="<<now<<endl;
			in[now]--;
			if(in[now]==0){
				q.push(now);
				if(DEBUG)cout<<"pushNow="<<now<<endl;
				ans[now]=top+1;
			}
		}
	}
 
	REP(i,0,n){
		cout<<ans[i]<<endl;
	}
 
	return 0;
}