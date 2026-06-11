#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <regex>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	string S; cin >> S;
	string patterns[] = {
		"keyence.*",
		"keyenc.*e" ,
		"keyen.*ce" ,
		"keye.*nce" ,
		"key.*ence" ,
		"ke.*yence" ,
		"k.*eyence" ,
		".*keyence" };

	for (const string & p : patterns) {
		if (regex_match(S, regex(p))) {
			print("YES");
			return 0;
		}
	}
	print("NO");
	return 0;
}