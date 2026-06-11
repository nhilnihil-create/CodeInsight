/*
Problem: Distance Sums (AtCoder 4434)
Algorithm: Math??Graph??
Status:
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <utility>
#include <list>
#include <ctime>
#include <memory.h>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

#define INF 1000000007
typedef long long ll;

int n;
map<ll,int> d;
vector<pair<ll,int> > ev;
vector<pair<int,int> > ans;
ll dp[100005],sz[100005];

void bye(){
	cout<<-1<<endl;
	exit(0);
}

int main()
{
	#ifndef ZZZYT
		//freopen(".in","r",stdin);
		//freopen(".out","w",stdout);
	#endif
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ll tmp;
		scanf("%lld",&tmp);
		ev.push_back(make_pair(tmp,i));
		d[tmp]=i;
	}
	sort(ev.rbegin(),ev.rend());
	ll center=ev.back().first;
	for(int i=0;i<n;i++)sz[i]=1;
	for(int i=0;i<ev.size();i++){
		int x=ev[i].second;
		ll s=ev[i].first;
		if(s!=center){
			if(sz[x]*2>=n)bye();
			ll ps=s+sz[x]-(n-sz[x]);
			if(d.count(ps)==0)bye();
			int p=d[ps];
			sz[p]+=sz[x];
			dp[p]+=dp[x]+sz[x];
			ans.push_back(make_pair(x,p));
		}
	}
	if(dp[ev.back().second]!=center)bye();
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}
	return 0;
}
