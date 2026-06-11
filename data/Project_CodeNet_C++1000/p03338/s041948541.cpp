#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int N;
	string S;
	cin >> N >> S;

	int mx = 0;
	for (int i=1; i<N-1; i++) {
		string s1 = S.substr(0, i);
		string s2 = S.substr(i, N-i);
		set<char> set1;
		set<char> set2;
		rep(i, s1.size()) {
			set1.insert(s1[i]);
		}
		rep(i, s2.size()) set2.insert(s2[i]);
		int cnt = 0;
		for (auto e1 : set1) {
			for (auto e2 : set2) {
				if (e1==e2) cnt++;
			}
		}
		mx = max(mx, cnt);
	}
	cout << mx << endl;
}