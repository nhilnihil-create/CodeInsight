//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 8000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

string s;
int x, y;
vector<int> X, Y;
bitset<2 * N> dp, dp2, dp3;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	s += "T";
	cin >> x >> y;
	int cnt = 0;
	int ted = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'T'){
			if (ted % 2 == 0) X.pb(cnt);
			else Y.pb(cnt);
			ted++;
			cnt = 0;
		}else{
			cnt ++;
		}
	}
	int c = 8010;
	dp[c] = 1;
	bool f = 0;
	for (auto u:X){
		//cout << u << ' ';
		if (!f) dp3 = (dp << u), f = 1;
		else dp3 = ((dp >> u) | (dp << u));
		dp = dp3;
	}
	//cout << '\n';
	dp3 = 0;
	dp2[c] = 1;
	for (auto u:Y){
		//cout << u << ' ';
		dp3 = ((dp2 >> u) | (dp2 << u));
		dp2 = dp3;
	}
	//cout << '\n';
	if (dp2[y + c] && dp[x + c]) return cout << "Yes", 0;
	cout << "No";








	return 0;
}
