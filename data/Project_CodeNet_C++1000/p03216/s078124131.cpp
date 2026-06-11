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

	int N, Q;
	string S;
	cin >> N >> S >> Q;


	REP(j, Q) {
		int a, ans = 0;
		int dcnt = 0, mcnt = 0, dmcnt = 0;
		int s = 0, t = 0;
		cin >> a;
		if (S[0] == 'D')dcnt++;
		if (S[0] == 'M')mcnt++;
		while (t < N) {

			/*int d = 0, m = 0;
			eFOR(i, s, t) {
				if (S[i] == 'D')d++;
				if (S[i] == 'M')m++;
			}


			if (j == 2) {
				cout << s << " " << t << " " << " " << dcnt << " " << mcnt << " " << dmcnt << endl;
				cout << d << " " << m << endl << endl;
			}*/
			if (S[t + 1] == 'C') ans += dmcnt;
			if (S[t + 1] == 'M') {
				if (t - s + 1 == a - 1) {
					if (S[s] == 'D') {
						mcnt++;
						dmcnt += dcnt - 1;
					}
					else {
						mcnt++;
						dmcnt += dcnt;
					}
				}
				else {
					mcnt++;
					dmcnt += dcnt;
				}
				t++;
			}
			else if (S[t + 1] == 'D') {
				t++;
				dcnt++;
			}
			else t++;

			if (t - s  == a - 1) {
				if (S[s] == 'D') {
					dmcnt -= mcnt;
					dcnt--;
					if (S[t] == 'M')dmcnt++;
				}
				if (S[s] == 'M') {
					mcnt--;
				}
				s++;
			}
		}
		
		
		cout << ans << endl;
	}



	return 0;
}

