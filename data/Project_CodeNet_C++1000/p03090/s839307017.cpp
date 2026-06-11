#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N;
	cin >> N;

	int S;
	if (N % 2 == 1) S = N;
	else S = N + 1;

	//int cnt = 0;
	cout << N * (N - 1) / 2 - N / 2 << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (j == S - i) continue;
			//cnt++;
			//cout << cnt << " ";
			cout << i << " " << j << endl;
		}
	}
}
