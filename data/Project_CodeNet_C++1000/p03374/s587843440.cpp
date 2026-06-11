//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

/***************************************************************************/

ll X[N], V[N];
ll bestL[N], bestR[N];

int main() {

	boost;
	int n; cin>>n;
	ll c; cin>>c;

	ll sum = 0;
	ll ans = 0;

	for(int i=1; i<=n; i++) {
		cin>>X[i]>>V[i];
		sum += V[i];
		bestL[i] = max(bestL[i-1], sum-X[i]);
		ans = max(ans, bestL[i]);
	}

	sum = 0;
	for(int i=n; i>=1; i--) {
		sum += V[i];
		bestR[i] = max(bestR[i+1], sum-c+X[i]);
		ans = max(ans, bestR[i]);
		ans = max(ans, sum-c+X[i]-c+X[i]+bestL[i-1]);
	}

	sum = 0;
	for(int i=1; i<=n; i++) {
		sum += V[i];
		ans = max(ans, sum-X[i]-X[i]+bestR[i+1]);
	}

	cout<<ans<<"\n";
	return 0;
}