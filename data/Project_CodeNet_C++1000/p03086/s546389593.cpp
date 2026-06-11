#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)


int main() {
	string s;
	cin >> s;

	int res = 0;
	int j;
	for(int i = 0; i < s.size(); ++i) {
		for (j = i; j < s.size(); ++j) {
			if (s[j] != 'A' && s[j] != 'C' && s[j] != 'G' && s[j] != 'T') break;
		}
		res = max(res, j - i);
	}
	

	cout << res << endl;
}