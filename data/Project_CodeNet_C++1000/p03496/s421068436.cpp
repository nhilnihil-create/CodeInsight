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
typedef priority_queue<int> PQ;
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
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N;
	cin >> N;
	VI A(N);
	vector<pair<int, int> > ans;
	int ma = 0, mi = 0,ab=0,abss=0,ai=0;
	REP(i, N) {
		cin >> A[i];
		ma = max(ma, A[i]);
		mi = min(mi, A[i]);
		if (ab < abs(A[i])) {
			ab = max(ab, abs(A[i]));
			abss = A[i];
			ai = i+1;
		}

	}
	if (ma >= 0 && mi >= 0) {
		REP(i, N - 1) {
			ans.push_back(make_pair(i + 1, i + 2));
		}
	}
	else if(ma<=0 && mi<=0){
		for (int i = N; i > 1;i--) {
			ans.push_back(make_pair(i, i - 1));
		}
	}
	else if (abss >= 0) {
		eFOR(i, 1, N) {
			if (ai != i)ans.push_back(make_pair(ai, i));
		}
		REP(i, N - 1) {
			ans.push_back(make_pair(i + 1, i + 2));
		}
	}
	else {
		eFOR(i, 1, N) {
			if (ai != i)ans.push_back(make_pair(ai, i));
		}
		for (int i = N; i > 1; i--) {
			ans.push_back(make_pair(i, i - 1));
		}
	}

	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}

