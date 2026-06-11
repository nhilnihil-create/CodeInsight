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
	if (N == 3) {
		cout << "2 5 63" << endl; return 0;
	}
	else if (N == 4) {
		cout << "2 5 20 63" << endl;
		return 0;
	}
	int a, b;
	if (N % 2) {
		a = min((N / 4 - 1) * 4 + 3, 9999LL);
		b = N - a;
	}
	else {
		a = min((N - 1) / 4 * 4, 10000LL);
		b = N - a;
	}
	FOR(i, 1, a + 1)cout << 3 * i << " ";
	int cnt = 0, x = 2;
	while (1) {
		if (x % 3 == 0) {
			x += 2;
			continue;
		}
		else {
			cout << x << (cnt != b - 1 ? " " : "\n");
			if (cnt == b - 1)break;
			else cnt++;
			x += 2;
		}
	}




	return 0;
}

