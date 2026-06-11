#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <utility>
#include <assert.h>
#include <regex>
#include <numeric>
using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
#define INF (1LL << 48)

struct PT { ll x; ll y; };
string to_s(ull x) { return to_string(x); }
string to_s(ll x) { return to_string(x); }
ll to_ll(const string& x) { return stoll(x); }
ull to_ull(const string& x) { return stoull(x); }




int main(int argc, char* argv[])
{
	for (;;) {
		string S;
		cin >> S;
		if (cin.fail()) break;

		int len = (int) S.length();
		array<int, 3> cnt{};
		for (int i = 0; i < len; i++) {
			cnt[S[i] - 'a']++;
		}
		sort(cnt.begin(), cnt.end(), greater<int>());
		cnt[0] -= len / 3;
		cnt[1] -= len / 3;
		cnt[2] -= len / 3;
		switch (len % 3) {
		case 0: break;
		case 1: cnt[0]--; break;
		case 2: cnt[0]--; cnt[1]--; break;
		}
		cout << ((cnt[0] | cnt[1] | cnt[2]) ? "NO" : "YES") << endl;
	}

	return 0;
}
