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
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int gcd(int a, int b) {//最大公約数
	if (b == 0)return a;
	return gcd(b, a%b);
}

bool solve(int A, int B, int C, int D) {

	if (B > A)return false;
	if (B > D)return false;
	if (C >= B)return true;

	A %= B;

	int g = gcd(B, D);
	if (B - g + A % g > C)return false;
	return true;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;

		if (solve(A, B, C, D))cout << "Yes" << endl;
		else cout << "No" << endl;

	}

	return 0;
}

