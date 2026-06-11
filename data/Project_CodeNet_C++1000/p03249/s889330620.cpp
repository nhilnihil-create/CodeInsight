#include <bits/stdc++.h>
#define FR first
#define SE second

using namespace std;

typedef long long ll;
typedef pair<ll,int> pr;

map <ll,int> mp;
pr num[100005];

vector <int> e[100005];
int siz[100005],dep[100005];

void dfs(int x) {
  for(int i=0;i<e[x].size();i++) {
  	int u=e[x][i];
  	dep[u]=dep[x]+1;
  	dfs(u);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
  	ll x;
  	scanf("%lld",&x);
  	num[i]=pr(x,i);
  	mp[x]=i;
  }
  sort(num+1,num+n+1);
  for(int i=1;i<=n;i++) siz[i]=1;
  for(int i=n;i>1;i--) {
  	int x=num[i].SE;
  	if (siz[x]*2>=n) {
  		puts("-1");
  		return 0;
	  }
	ll v=num[i].FR-(n-2*siz[x]);
	if (!mp.count(v)) {
		puts("-1");
		return 0;
	}
	int p=mp[v];
	e[p].push_back(x);
	siz[p]+=siz[x];
  }
  if (siz[num[1].SE]!=n) {
  	puts("-1");
  	return 0;
  }
  dfs(num[1].SE);
  ll s=0;
  for(int i=1;i<=n;i++) s+=dep[i];
  if (s!=num[1].FR) {
  	puts("-1");
  	return 0;
  }
  for(int i=1;i<=n;i++)
    for(int j=0;j<e[i].size();j++) printf("%d %d\n",i,e[i][j]);
  return 0;
}