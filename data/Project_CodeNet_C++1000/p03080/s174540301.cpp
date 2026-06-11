#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<int> VI;
const ll MOD = 1000000007;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	int n;
	cin >> n;
	char s[100];
	cin >> s;
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')
			r++;
	}
	if (r * 2 > n)
		cout << "Yes";
	else
		cout << "No";
}