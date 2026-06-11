#include<iostream>
#include<cstdlib>
#include<deque>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int start = s[0] - '0';
	deque<int> set;
	int prev = start;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (prev != s[i] - '0') {
			set.push_back(count);
			count = 1;
		}
		else {
			count++;
		}
		prev= s[i] - '0';
	}
	set.push_back(count);
	if (set.size() <= 2 * k) {
		cout << n << endl;
	}
	else {
		if (start == 0) {
			set.push_front(0);
		}
		if (set.back()==0) {
			set.push_front(0);
		}
		int maxi = 0;
		for (int i = 0; i < 2 * k + 1; i++) {
			maxi += set[i];
		}
		int prev = maxi;
		for (int i = 0; i < set.size() - 2 * k - 2; i += 2) {
			prev = prev - set[i] - set[i + 1] + set[2 * k + 1 + i] + set[2 * k + i + 2];
			int temp = max(maxi, prev);
			maxi = temp;
		}
		if (set.size() % 2 == 0) {
			maxi = max(maxi, prev - set[set.size() - 2 * k - 2] - set[set.size() - 2 * k - 1] + set[set.size() - 1]);
		}
		cout << maxi << endl;

	}
	return 0;
}