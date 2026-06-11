#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#include <bitset>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INT_INF = 2147483647;
const long long int LL_INF = 9223372036854775807;
const double PI = acos(-1);
const double EPS = 0.0001;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(full(a), greater<int>());
	cout << a[0] << " ";
	for (int i = 1; i < n; i++) {
		if (a[i] < a[0] / 2) {
			if (i == 1 || a[0] / 2 - a[i] < a[i - 1] - a[0] / 2) {
				cout << a[i] << endl;
			}
			else {
				cout << a[i - 1] << endl;
			}
			break;
		}
	}
	return 0;
}
