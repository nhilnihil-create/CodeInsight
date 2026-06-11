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

	vector<int> b(N);
	for (int i = 0; i < N; i++)
		cin >> b[i];

	bool flag = true;
	vector<int> ans(N);
	for (int i = N-1; i >= 0&&flag; i--) {
		flag = false;
		for (int j = i; j >= 0; j--) {
			if (b[j] <= i + 1 && j+1 == b[j]) {
				ans[i] = b[j];
				b.erase(b.begin() + j);
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		for (int i = 0; i < N; i++) {
			cout << ans[i] << endl;
		}
	}
	else
		cout << -1 << endl;
}
