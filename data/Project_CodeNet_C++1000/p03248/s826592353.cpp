#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	int N = s.size();
	s = "0" + s;
	bool fl = true;

	/*
	for (int i = 0; i <= N; i++) {
		cout << "i=" << i << " s[i]=" << s[i] << endl;
	}
	*/
	for (int i = 0; i <= N / 2; i++) {
		if (s[i] != s[N - i]) {
			//cout << "i=" << i << endl;
			fl = false;
			break;
		}
	}

	if (s[1] == '0')fl = false;
	if (!fl)cout << -1 << endl;
	else {
		vector<pair<int, int>> ed;
		int left = 1;
		for (int i = 2; i <= N - 1; i++) {
			if (s[i] == '1') {
				for (int j = left; j < i; j++) {
					ed.push_back(make_pair(j, i));
				}
				left = i;
			}
		}
		ed.push_back(make_pair(N - 1, N));
		for (int i = 0; i < ed.size(); i++) {
			cout << ed[i].first << " " << ed[i].second << endl;
		}
	}
}
