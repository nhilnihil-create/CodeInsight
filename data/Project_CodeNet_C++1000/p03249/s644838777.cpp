#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

const int N=1e5+5;
int n,rt;
map<long long,int> mp;
int sz[N];
long long dp[N];
priority_queue<long long> pq;
vector<int> nei[N];

void dfs(int x){
	for(int i=0;i<nei[x].size();i++){
		dfs(nei[x][i]);
		dp[x]+=dp[nei[x][i]]+sz[nei[x][i]];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		mp[x]=i;
		pq.push(x);
		sz[i]=1;
	}
	while(!pq.empty()){
		long long num=pq.top();
		pq.pop();
		int x=mp[num];
		rt=x;
		if(pq.empty()) break;
		num-=n-sz[x];
		num+=sz[x];
		if(mp.find(num)==mp.end()){
			puts("-1");
			return 0;
		}
		int y=mp[num];
		sz[y]+=sz[x];
		nei[y].push_back(x);
	}
	dfs(rt);
	if(dp[rt]!=(mp.begin())->first){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=0;j<nei[i].size();j++) printf("%d %d\n",i,nei[i][j]);
	return 0;
}