#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 10e9;
const int MAX_V = 201;
double ft[103];
double tt[103];
double v[103];

void AtCoderExpress() {
	int n;
	cin >> n;
	int T = 0;
	for (size_t i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		//t *= 2;
		T += t;
		ft[i] = T - t;
		tt[i] = T;
	}
	tt[n + 1] = T;
	ft[n + 1] = T;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	double res = 0;
	double prev = 0;
	for (double i = 0.5; i <= T; i += 0.5)
	{
		double minu = 100;
		for (int j = 0; j <= n + 1; j++)
		{
			if (j >= 1 && ft[j] <= i && i <= tt[j]) {
				minu = min(minu, v[j]);
			}

			if (tt[j] < i) {
				minu = min(minu, v[j] + (i - tt[j]));
			}

			if (j >= 1 && i < ft[j]) {
				minu = min(minu,v[j] + (ft[j] - i));
			}
			
		}

		res +=  (prev + minu) * 0.25;
		prev = minu;
	}
	cout << to_string(res) << endl;
}

int main() {
	AtCoderExpress();
	return 0;
}

