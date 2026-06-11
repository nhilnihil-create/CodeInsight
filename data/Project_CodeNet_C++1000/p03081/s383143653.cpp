#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>

using namespace std;

string s;
int q, n;
char t[200000];
char d[200000];

int Serch(int check) {
	for (int i = 0; i < q; i++) {
		if (t[i] == s[check]) {
			if (d[i] == 'L') {
				check--;
			}
			else {
				check++;
			}
		}
		if (check < 0) { return -1; }
		if (check >= n) {
			return -2;
		}
	}
	return -3;
}


int main() {
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> d[i];
	}


	int high = n;
	int low = 0;
	int left;
	int left_max = 0;
	//左側から落ちるものを二分探索,そのうち一番右を探す
	while (high - low > 1) {
		left = (high + low) / 2;
		if (Serch(left) == -1) {
			low = left;
			left_max = max(left_max, left);
		}
		else {
			high = left;
		}
	}


	high = n;
	low = 0;
	int right;
	int right_min = n;
	//右側から落ちるものを二分探索,そのうち一番左を探す
	while (abs(high - low) > 1) {
		right = (high + low) / 2;
		if (Serch(right) == -2) {
			high = right;
			right_min = min(right_min, right);
		}
		else {
			low = right;
		}
	}

	//cout << right_min << " " << left_max << endl;

	cout << right_min - left_max - 1 << endl;

}