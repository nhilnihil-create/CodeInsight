#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	long double n,k;
	cin>>n>>k;
	long double ans=0;
	for(ll i=1;i<=n;i++){
		ll now=i;
		long double cnt=1/n;
		while(now<k){
			now*=2;
			cnt/=2.0;
		}
		ans+=cnt;
	}
	printf("%.10Lf",ans);
	// your code goes here
	return 0;
}