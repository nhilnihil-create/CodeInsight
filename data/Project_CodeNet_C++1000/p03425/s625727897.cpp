#include <iostream>
#include <algorithm> 
#include <cmath>
//#include <bitset>
//#include <deque>
#include <iterator>
#include <map> 
//#include <queue>
//#include <stack>
#include <string>
#include <vector>
#include <array>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 


int C(int a, int b) {
	int ans = 1;
	for (int i = 1; i <= a; ++i) {
		ans *= i;
	}
	for (int i = 1; i <= a - b; ++i) {
		ans /= i;
	}
	for (int i = 1; i <= b; ++i) {
		ans /= i;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	string p = "MARCH";
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector<ll> v(5);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (s[i][0] == p[j]) {
				v[j]++;
			}
		}
	}
	//for (int i = 0; i < 5; ++i) {
		//cout << v[i] << " ";
	//}
	ll ans = 0;
	for (int i = 0; i < pow(2,5); ++i) {
		int op = 0;
		ll val = 1;
		for (int j = 0; j < 5; ++j) {
			if ((i >> j) & 1) {
				val *=  v[j];
				op++; 
			}
		}
		if (op == 3) {
			ans += val;
		}
	}
	//for (int i = 0; i < 3; ++i) {
		//int ap = 1;
		//for (int j = i; j < 5; ++j) {
			//ap *= C(v[j],1);
		//}
		//ans += ap;
	//}
	cout << ans;
}







