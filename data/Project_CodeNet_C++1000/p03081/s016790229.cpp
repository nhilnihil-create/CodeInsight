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

int N, Q;
string s;
vector<pair<char, char>> qs;
vector<int> ter;
int mv(int n) {
	if (ter[n] != -2)return ter[n];
	int Q = qs.size();
	int now = n;
	//cout << "n=" << n << endl;
	for (int i = 0; i < Q; i++) {
		if (qs[i].first == s[now]) {
			if (qs[i].second == 'L')now--;
			if (qs[i].second == 'R')now++;
		}
		if (now <= -1) return ter[n] = -1;
		if (now >= N)return ter[n] = N;
		//cout << "now=" << now << endl;
	}

	return ter[n] = now;
}

int main() {
	cin >> N >> Q;
	cin >> s;
	qs = vector<pair<char, char>>(Q);
	for (int i = 0; i < Q; i++) {
		cin >> qs[i].first >> qs[i].second;
	}

	ter = vector<int>(N, -2);
	int L = -1;
	int left = 0, right = N - 1;
	while (left < right) {
		int mid = (left + right + 1) / 2;
		if (mv(mid) == -1)left = mid;
		else right = mid - 1;
	}
	if (mv(left) == -1) L = left + 1;
	else L = 0;
	//cout << "L=" << L << endl;


	int R = -1;
	left = 0, right = N - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (mv(mid) == N)right = mid;
		else left = mid + 1;
	}
	if (mv(right) == N) R = N - right;
	else R = 0;
	//cout << "R=" << R << endl;

	cout << N - min(N, L + R) << endl;

}
