#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100000
#define mp make_pair
#define X first
#define Y second
#define pb push_back
int n;
int dsum[N+1],sz[N+1];
vector<int> nei[N+1];
int dfs(int x=1,int dep=0,int fa=0){
//	cout<<x<<" visiting\n";
	int res=dep;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y!=fa)res+=dfs(y,dep+1,x);
	}
	return res;
}
pair<int,int> pc[N+1];int oid[N+1];
vector<pair<int,int> > ans;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",dsum+i),pc[i]=mp(dsum[i],i);
	sort(dsum+1,dsum+n+1);sort(pc+1,pc+n+1);
	for(int i=1;i<=n;i++)oid[i]=pc[i].Y;
	fill(sz+1,sz+n+1,1);
	for(int i=n;i>=2;i--){
		int fadsum=dsum[i]+2*sz[i]-n;
		int fd=lower_bound(dsum+1,dsum+i,fadsum)-dsum;
		if(dsum[fd]!=fadsum)return puts("-1"),0;
		sz[fd]+=sz[i];
		ans.pb(mp(fd,i));
		nei[fd].pb(i);nei[i].pb(fd);
	}
//	for(int i=1;i<=n;i++){for(int j=0;j<nei[i].size();j++)cout<<nei[i][j]<<" ";puts("");}
	if(dfs()!=dsum[1])return puts("-1"),0;
	for(int i=0;i<ans.size();i++)printf("%lld %lld\n",oid[ans[i].X],oid[ans[i].Y]);
	return 0;
}

/*1
7
10
15
13
18
11
14
19
*/
/*2
2
1
2
*/
/*3
15
57
62
47
45
42
74
90
75
54
50
66
63
77
87
51
*/