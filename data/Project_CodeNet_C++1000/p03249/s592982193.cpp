#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=100010;
pair<long long,int> p[N];
int n,s[N];
ll S[N];
vector< pair<int,int> > ans;

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&p[i].first),p[i].second=i,s[i]=1;
	sort(p+1,p+n+1);
	for(int i=n; i>1; --i){
		if (n-2*s[i]<0) { puts("-1"); return 0; }
		int x=lower_bound(p+1,p+n+1,make_pair(p[i].first-n+2*s[i],0))-p;
		if(p[x].first!=p[i].first-n+2*s[i]) { puts("-1"); return 0; }
		s[x]+=s[i]; S[x]+=S[i]+s[i]; ans.push_back(make_pair(p[x].second,p[i].second));
	}
	if (S[1]!=p[1].first) { puts("-1"); return 0; }
	for(int i=0; i<(int)ans.size(); ++i) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}