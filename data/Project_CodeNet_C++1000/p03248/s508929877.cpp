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

	string S;
	cin >> S;
	int N = S.size();
	VI A(N+1);
	REP(i, N) A[i+1] = S[i] - '0';

	if (!A[1] || A[N]) {
		cout << -1 << endl;
		return 0;
	}
	eFOR(i, 1, N) {
		if (A[i] ^ A[N - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<pii> ans;
	ans.push_back(pii(1, 2));
	int tmp = 2;
	FOR(i, 2, N) {
		if (A[i]) {
			ans.push_back(pii(tmp, i + 1));
			tmp = i + 1;
		}
		else {
			ans.push_back(pii(tmp, i + 1));
		}
	}
	for (auto out : ans) {
		cout << out.first << " " << out.second << endl;
	}
	return 0;
}

