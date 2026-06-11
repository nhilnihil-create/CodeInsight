#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int l = 0, r = n - 1;
	string s[n];
	{
		cout << l << '\n';
		cout.flush();
		cin >> s[l];
		if(s[l] == "Vacant") return 0;
	}
	{
		cout << r << '\n';
		cout.flush();
		cin >> s[r];
		if(s[r] == "Vacant") return 0;
	}
	while(true) {
		int mid = (l + r) / 2;
		cout << mid << '\n';
		cout.flush();
		cin >> s[mid];
		if(s[mid] == "Vacant") return 0;
		if((mid - l) % 2 == 1) {
			if(s[l] == s[mid]) {
				r = mid;
			}
		}
		if((mid - l) % 2 == 0) {
			if(s[l] != s[mid]) {
				r = mid;
			}
		}
		if((r - mid) % 2 == 1) {
			if(s[r] == s[mid]) {
				l = mid;
			}
		}
		if((r - mid) % 2 == 0) {
			if(s[r] != s[mid]) {
				l = mid;
			}
		}
	}
	return 0;
}
