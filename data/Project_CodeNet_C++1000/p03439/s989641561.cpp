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

int N;

int Q(int ans) {
	string S;
	cout << ans << endl;
	cin >> S;
	if (S[0] == 'V')return -1;
	else return S[0] == 'M' ? 1 : 0;
}


signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	cin >> N;
	int L = 0, R = N - 1, F = Q(0);
	if (F == -1)return 0;
	while (L <= R) {

		int M = (L + R) / 2;
		int P = Q(M);
		if (P == -1)return 0;
		if (P == F) {
			if (M % 2)R = M - 1;
			else L = M + 1;
		}
		else {
			if (M % 2)L = M + 1;
			else R = M - 1;
		}
	}


	return 0;
}

