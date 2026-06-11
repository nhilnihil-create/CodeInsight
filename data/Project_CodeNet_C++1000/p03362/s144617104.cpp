#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 2000000000;
constexpr auto MOD = 1000000007;

int main() {
	int n;
	cin >> n;

	vi ans = {};

	rep1(i, 55555) {
		if (i == 1||i%5!=1)continue;
		bool prime=true;

		rep1(j,(int)sqrt(i)) {
			if (j == 1)continue;
			if (i % j==0)prime = false;
		}

		if (prime)ans.push_back(i);
	}

	rep(i, n)cout << ans[ans.size()-1-i] << " " << endl;
	cout << endl;
}