#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>ans[1005];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=1000;i++){
		if(i*(i-1)/2 != n) continue;
		puts("Yes");
		int cur = 0;
		for(int j=0;j<i;j++) for(int k=j+1;k<i;k++){
			ans[j].pb(cur);
			ans[k].pb(cur);
			cur++;
		}
		printf("%d\n",i);
		rep(j,i){
			printf("%d ",ans[j].size());
			rep(k,ans[j].size()) printf("%d ",1+ans[j][k]);
			puts("");
		}
		return 0;
	}
	puts("No");
}