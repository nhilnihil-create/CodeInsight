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

	int A, B;
	cin >> A >> B;
	A--;
	B--;
	char c[100][100];
	REP(i, 50) {
		REP(j, 100) {
			c[i][j] = '#';
		}
	}
	FOR(i, 50, 100) {
		REP(j, 100) {
			c[i][j] = '.';
		}
	}

	for(int i=0;i<49;i+=2) {
		for (int j = 0; j < 100; j+=2) {
			if (A > 0) {
				c[i][j] = '.';
				A--;
			}
		}
		
	}
	for(int i=51;i<100;i+=2) {
		for (int j = 0; j < 100; j += 2) {
			if (B > 0) {
				c[i][j] = '#';
				B--;
			}
		}
	}
	cout << 100 << " " << 100 << endl;
	REP(i, 100) {
		REP(j, 100) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}

