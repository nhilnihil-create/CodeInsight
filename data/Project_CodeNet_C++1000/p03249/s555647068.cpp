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
using namespace std;

const int N=1e5+5;
typedef pair<int,int> pii;
int n;
pair<long long,int> a[N];
long long sz[N];
long long dp[N];
vector<pii> vp;
map<long long,int> mp;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++) mp[a[i].first]=i;
	for(int i=1;i<=n;i++) sz[i]=1ll;
	for(int i=1;i<n;i++){
		long long fnd=a[i].first-1ll*n+2*sz[i];
		if(mp.find(fnd)==mp.end()){
			puts("-1");
			return 0;
		}
		int nxt=mp[fnd];
		dp[nxt]+=dp[i]+sz[i];
		sz[nxt]+=sz[i];
		vp.push_back(make_pair(a[i].second,a[nxt].second));
	}
	if(vp.size()!=n-1||dp[n]!=a[n].first) puts("-1");
	else for(int i=0;i<vp.size();i++) printf("%d %d\n",vp[i].first,vp[i].second);
	return 0;
}

/*
数据不清空，爆零两行泪
读题不认真，爆零两行泪
分析不仔细，爆零两行泪
建树不构造，爆零两行泪
变量不统一，爆零两行泪
边界不算清，爆零两行泪
数组不开大，爆零两行泪
*/