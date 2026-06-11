#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {
	
	int n;
	cin >> n;

	int last_a = 0, first_b = 0, b_to_a = 0;
	int cnt = 0;
	rep(i, n) {
		string s;
		cin >> s;
		rep(i, s.size() - 1)if (s[i] == 'A' && s[i + 1] == 'B')cnt++;
		if (s[0] == 'B' && s[s.size() - 1] == 'A')b_to_a++;
		else if (s[s.size() - 1] == 'A')last_a++;
		else if (s[0] == 'B')first_b++;
		
	}

	if (last_a == 0 && first_b == 0 && b_to_a > 0)cnt += b_to_a - 1;
	else cnt += min(last_a, first_b) + b_to_a;

	cout << cnt << endl;

}