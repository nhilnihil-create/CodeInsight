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
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//priority_queue<int,vector<int>, greater<int> > q2;

int P;

int modpow(int a, int p) {
	if (p == 0) return 1;
	if (p % 2 == 0) {

		int halfP = p / 2;
		int half = modpow(a, halfP);
		if (half > P)return -1;
		return half * half;
	}
	else {
		int b = modpow(a, p - 1);
		if (b > P)return -1;
		return a * b;
	}
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N >> P;
	if (N == 1) {
		cout << P << endl;
		return 0;
	}
	int ans = 1;
	int i = 2;
	while (1) {
		int tmp = modpow(i, N);
		//cout << tmp << endl;
		if (tmp <= 1)break;
		if (tmp > P)break;
		if (P%tmp == 0)chmax(ans, i);
		i++;
	}


	cout << ans << endl;

	return 0;
}

