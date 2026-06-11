#include "bits/stdc++.h"
using namespace std; 
#define LIM 3003

#define M 1000000007
#define inf 99999999999999999LL	//long long inf
typedef long long ll;

#define sc(x) scanf("%d",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define scl(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld%lld",&x,&y);
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);

#define pb push_back
#define mp make_pair
#define fi first
#define se second 
ll power(ll x,ll y,ll z) {	ll ret = 1;	while(y > 0) {	if(y & 1) ret = (ret*x)%z;x = (x*x)%z;y >>= 1;}return ret;}


#define debug(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define debug4(x,y,z,a) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#a<<" :: "<<a<<"\n";


ll n, dp[LIM][LIM], pref[LIM];
char s[LIM];

int main() {
	int i, j, t;
	scl(n);
	scanf("%s", 1+s);
	dp[1][1] = 1;
	for(i=1; i<=n; i++)
		pref[i] = 1;
	for(i=2; i<=n; i++) {
		
		for(j=1; j <= i; j++) {
			if (s[i-1] == '<') {
				dp[i][j] = pref[j-1];
			} else {

				dp[i][j] = (pref[i] - pref[j-1] + M)%M;
			}
			//debug3(i, j, dp[i][j]);	
		}
		for(j=1; j<=n; j++) {
			pref[j] = (pref[j-1] + dp[i][j])%M;
		}
	}



	cout << pref[n] << endl;
	return 0;
}


