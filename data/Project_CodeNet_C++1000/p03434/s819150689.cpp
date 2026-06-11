#include <iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int x = 0;
	int y = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			x += a.at(i);
		}
		else {
			y += a.at(i);
		}
	}
	cout << x - y << endl;
}