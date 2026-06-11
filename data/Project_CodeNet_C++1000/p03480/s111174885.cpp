#include<iostream>
#include<array>
#include<vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include<cmath>

using llint = long long int;
using namespace std;

string S;
int inf = 1000000007;

int main() {
	cin >> S;
	char c = S[0];
	int N = S.size();
	int k = inf;
	if (count(S.begin(), S.end(), '0') == N || count(S.begin(), S.end(), '1') == N) { cout << N << endl; return 0; }
	for (int i = 1; i < N; i++) {
		if (c != S[i]) {
			//cout << i << endl;
			//後半が大きい場合後半Flip
			if (i < N - i) {
				k = min(k, N - i);
			}
			//前半が大きい場合前半Flip
			else if (i > N - i) {
				k = min(k, i);
			}
			//ちょうど中間
			else {
				k = N / 2;
			}
			c = (c == '0' ? '1' : '0');
		}
	}
	cout << k << endl;
	return 0;
}

