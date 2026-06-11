#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int>v;
	map<int, int>w;
	bool vi = true;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (vi) {
			if (v.count(x))v.at(x)++;
			else v[x] = 1;
			vi = false;
		}
		else {
			if (w.count(x))w.at(x)++;
			else w[x] = 1;
			vi = true;
		}
	}
	int mod_odd = 0;
	int mod2_odd = 0;
	int odd_num = 0;
	int even_num = 0;
	for (auto x : v) {
		if (mod_odd <= x.second) {
			odd_num = x.first;
			mod2_odd = mod_odd;
			mod_odd = x.second;
		}
		else if(mod2_odd <=x.second){
			mod2_odd = x.second;
		}
	}
	int mod_even = 0;
	int mod2_even = 0;
	for (auto x : w) {
		if (mod_even <= x.second) {
			even_num = x.first;
			mod2_even = mod_even;
			mod_even = x.second;
		}
		else if (mod2_even <= x.second){
			mod2_even = x.second;
		}
	}
	if (odd_num != even_num) {
		cout << n - mod_odd - mod_even << endl;
	}
	else {
		if (mod2_odd > mod2_even)cout << n - mod2_odd - mod_even << endl;
		else cout << n - mod2_even - mod_odd << endl;
	}
}
