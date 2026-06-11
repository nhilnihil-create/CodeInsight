#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>	
#include <deque>
#include <set>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define fore(i,a) for(auto &i:a)
#define INF INT_MAX/2;
typedef long long ll;
using namespace std;
using vi = vector<int>;
using vll = vector<ll>;
ll mod = 1e9 + 7;
//ll llmax = 10000000000000000000ll;
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;

	string s;
	cin >> n >> s;
	vector<int> w(n+1);
	vector<int> e(n+1);

	rep(i, 0, n) {
		if (s[i] == 'W') {
			w[i + 1] = w[i] + 1;
		}
		else
		{
			w[i + 1] = w[i];
		}
	}

	rep(i, 0, n) {
		if (s[i] == 'E') {
			e[i + 1] = e[i] + 1;
		}
		else
		{
			e[i + 1] = e[i];
		}
	}
	int ans = n;

	rep(i, 0, n) {

		ans = min(ans, w[i] + e[n] - e[i + 1]);
	}

		
	cout << ans << endl;

	
	
}
	