#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000000000007LL
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

int n;
pair<pii, int> z[1005];

int dp[1005][20005];

bool cmp(pair<pii, int> x,pair<pii, int> y){
	pii a=x.fr,b=y.fr;
	return a.sc+a.fr > b.sc+b.fr;
}

int calc(int p,int s){
	if(s<0)return -M;
	if(p==n)return 0;
	int &ans=dp[p][s];
	if(ans!=-1)return ans;
	ans=calc(p+1,s);
	ans=max(ans,z[p].sc+calc(p+1,min(s-z[p].fr.fr,z[p].fr.sc)));
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n;
	rep(i,0,n){
		cin>>z[i];
	}
	sort(z,z+n,cmp);
	// rep(i,0,n)cout<<z[i]<<"\n";
	int ans=0;
	ans=calc(0,20001);
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}