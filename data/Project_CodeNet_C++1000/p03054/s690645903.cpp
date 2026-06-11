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

	int H, W, N;
	cin >> H >> W >> N;

	int h, w;
	cin >> h >> w;

	string S, T;
	cin >> S >> T;

	int left = 1, right = W;
	if (S[N - 1] == 'L')left++;
	if (S[N - 1] == 'R')right--;

	for(int i = N - 2; i >= 0; i--) {
		if (T[i] == 'L')right = min(right + 1, W);
		else if (T[i] == 'R')left = max(1LL, left - 1);

		if (S[i] == 'L')left++;
		else if (S[i] == 'R')right--;
		
		if (left > right) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (left > w || w > right) {
		cout << "NO" << endl;
		return 0;
	}
	left = 1, right = H;
	if (S[N - 1] == 'U')left++;
	if (S[N - 1] == 'D')right--;

	for (int i = N - 2; i >= 0; i--) {
		if (T[i] == 'U')right = min(right + 1, H);
		else if (T[i] == 'D')left = max(1LL, left - 1);

		if (S[i] == 'U')left++;
		else if (S[i] == 'D')right--;

		if (left > right) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (left > h || h > right) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;


	return 0;
}

