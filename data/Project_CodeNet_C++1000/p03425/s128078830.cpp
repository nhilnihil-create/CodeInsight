#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	string _s = "MARCH";
	map<char, long long> mp;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (size_t j = 0; j < _s.length(); ++j) {
			if (s[0] == _s[j]) {
				mp[s[0]]++;
				break;
			}
		}
	}

	long long ans = 1;
	if (mp.size() < 3) {
		cout << 0 << endl;
	}
	else if (mp.size() == 3) {
		for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
			ans *= iter->second;
		}
		cout << ans << endl;
	}
	else {
		ans = 0;
		for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
			auto iter2 = iter;
			for (iter2++; iter2 != mp.end(); ++iter2) {
				auto iter3 = iter2;
				for (++iter3; iter3 != mp.end(); ++iter3) {
					ans += iter->second * iter2->second * iter3->second;
				}
			}
		}

		cout << ans << endl;
	}
	
	return 0;
}