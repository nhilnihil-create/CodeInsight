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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a,b;
int main(){
	cin>>n>>a>>b;
	if(a == 1){
		if(b != n) puts("-1");
		else{
			for(int i=n;i>=1;i--) cout<<i<<" ";
			cout<<endl;
			return 0;
		}
	}
	for(int aa=2;aa<=a;aa++){
		int x = n+1-b-aa;
		if(x%(a-1) != 0) continue;
		x /= (a-1);
		if(1LL*a*x+aa > n || x<0) continue;
		if(aa!=a && x==0) continue;
		vector<int>ans;
		for(int i=1;i<=x;i++){
			vector<int>vi;
			for(int j=0;j<a;j++){
				vi.pb(n--);
			}
			reverse(vi.begin(),vi.end());
			rep(i,vi.size()) ans.pb(vi[i]);
		}
		{
			vector<int>vi;
			for(int j=0;j<aa;j++){
				vi.pb(n--);
			}
			reverse(vi.begin(),vi.end());
			rep(i,vi.size()) ans.pb(vi[i]);
		}
		while(n>=1){
			ans.pb(n--);
		}
		rep(i,ans.size()) printf("%d ",ans[i]);
		puts("");
		return 0;
	}
	puts("-1");
}