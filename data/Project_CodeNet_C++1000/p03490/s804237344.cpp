#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

bool dp[2][16161];
string s; 

bool solve(int g, int mod, vector<int> a) {
	
	rep(i,2) rep(j,16161) dp[i][j]=false;

	dp[0][8000]=true;
	
	int i=0;
	if (!mod) {
		rep(j,16161) {
			if (!dp[0][j]) continue;
			dp[i][j]=false;
			dp[i+1][j+a[i]]=true;
			// cout << "i = "<<i<<", j+a[i] = "<<j+a[0] << endl;
		}
	}

	for (; i < a.size(); ++i) {
		rep(j,16161) {
			if (!dp[i%2][j]) continue;
			dp[i%2][j]=false;
			dp[(i+1)%2][j+a[i]]=true;
			dp[(i+1)%2][j-a[i]]=true;
			// cout<< "i = "<<i%2<<", j+a[i] = "<<j+a[i]<<", j-a[i] = "<<j-a[i]<< endl;
		}
	}

	if (dp[a.size()%2][g+8000]) return true;
	else return false;
}

int main(int argc, char const *argv[]) {
	int x,y;
	cin>>s>>x>>y;
	int n = s.length();
	vector<int> a;
	vector<int> X,Y;

	// ランレングス変換をします
	int cnt=0;
	rep(i,n) {
		if (s[i]=='F') cnt++;
		else {
			a.push_back(cnt);
			cnt=0;
		}
	}
	if (cnt) a.push_back(cnt);

	rep(i,a.size()) {
		if (i%2==0) X.push_back(a[i]);
		else Y.push_back(a[i]);
	}

	if (solve(x,0,X)&&solve(y,1,Y)) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}