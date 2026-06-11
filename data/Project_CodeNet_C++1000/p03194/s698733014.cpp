#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <cstring>
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
	ll n, p, w = 1;
	cin >> n >> p;
	if (n == 1) {
		cout << p << endl;
		return 0;
	}
	for (ll i = 2; i*i <= p; i++) {
		if (p%i == 0) {
			ll cnt = 1;
			p /= i;
			while (p%i == 0) {
				cnt++;
				p /= i;
				if (cnt == n) {
					w *= i;
					cnt = 0;
				}
			}
		}
	}
	cout << w << endl;
	return 0;
}
