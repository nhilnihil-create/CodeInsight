#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
int k[26];
int main() {
	string s;
	cin >> s;
	int a = -1;
	if (s[0] != 'z')a = 0;
	rep(i, 0, s.size()) {
		k[s[i] - 'a'] = 1;
		if (i && s[i - 1] - s[i] != 1)a = i;
	}
	if (a == -1) {
		puts("-1");
		return 0;
	}
	rep(i, 0, 26) {
		if (!k[i]) {
			cout << s << (char)('a' + i);
			return 0;
		}
	}
	string t = s;
	next_permutation(all(s));
	rep(i, 0, s.size()) {
		cout << s[i];
		if (s[i] != t[i])break;
	}
	return 0;
}