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



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, A, B; cin >> N >> A >> B;
	if (A + B > N + 1 || A * B < N) {
		cout << -1 << endl;
		return 0;
	}
	deque<int> ans;
	int a = A;
	int n = 1;
	vector<bool>F(N+1, false);
	while (1) {
		ans.push_front(a);
		F[a--] = 1;
		//cout << B << " " << (int)ans.size() << endl;
		
		if (a%A == 0) {
			n++;
			a = A * n;
			B--;
			//cout << "L" << endl;
			chmin(a, N);
			//if (a > N)break;
		}
		if (B == (N - (int)ans.size()))break;
	}
	n = N;

	while (N != ans.size()) {
		if (!F[n]) {
			cout << n-- << " ";
			N--;
		}
		else n--;
	}
	while (ans.size() != N) {
		if(!F[n])ans.push_front(n--);
		else n--;
	}
	REP(i, N) {
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}

