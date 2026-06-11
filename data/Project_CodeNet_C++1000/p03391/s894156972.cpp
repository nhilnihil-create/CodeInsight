#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n,a[200005],b[200005];
ll ans;
ll mn = 1e18;
bool dif;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		ans += b[i];
		if(a[i] != b[i]) dif = 1;
		if(a[i] > b[i]) mn = min(mn,1LL*b[i]);
	}
	if(!dif){
		puts("0"); return 0;
	}
	cout<<ans-mn<<endl;
}