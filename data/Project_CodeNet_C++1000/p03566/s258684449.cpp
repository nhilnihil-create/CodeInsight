#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<double> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000001
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	VI T(N);
	VI V(N);

	int Tsum = 0;
	
	double maxv[40010];
	REP(i, 40010) {
		maxv[i] = (double)INF;
	}

	REP(i, N) {
		cin >> T[i];
		Tsum += T[i];
	}
	REP(i, N) {
		cin >> V[i];
	}

	int now = 0;
	REP(i, N) {
		REP(t, T[i]) {
			int a = now + t * 2;
			int b = now + t * 2 + 1;

			maxv[a] = min(maxv[a], V[i]);
			maxv[b] = min(maxv[b], V[i]);
		}
		now += T[i] * 2;
		maxv[now] = min(maxv[now], V[i]);
	}
	maxv[0] = 0.0;
	maxv[Tsum * 2] = 0.0;

	for (int i = 0; i < Tsum * 2+1; i++) {
		maxv[i+1] = min(maxv[i] + 0.5, maxv[i+1]);
	}

	for (int i = Tsum * 2+1; i >= 0; i--) {
		maxv[i] = min(maxv[i + 1] + 0.5, maxv[i]);
	}

	double ans = 0;

	for (int i = 0; i < Tsum * 2 + 1; i++) {
		ans += (maxv[i] + maxv[i + 1]) *0.5/2.0;
	}
	printf("%.4f\n", ans-0.1250);
	return 0;
}

