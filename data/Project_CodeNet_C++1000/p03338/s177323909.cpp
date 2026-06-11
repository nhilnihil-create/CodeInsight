#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}

int main() {
	vector<int> list1(26, 0), list2(26, 0);
	int N, ans = 0;
	string S;
	cin >> N >> S;


	for (const char& c : S) list2[c - 'a']++;
	for (int i = 0; i < N-1; i++) {
		int index = S[i] - 'a';
		list1[index]++;
		list2[index]--;

		int count = 0;
		for (int n = 0; n < 26; n++) {
			if (list1[n]> 0 && list2[n] > 0) count++;
		}
		ans = max(ans, count);
	}
	print(ans);
}