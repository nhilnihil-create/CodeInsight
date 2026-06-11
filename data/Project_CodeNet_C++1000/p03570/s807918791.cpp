#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<deque>
#include<string>
#include<random>
#include<stack>
#include<limits.h>
#define int long long
using namespace std;

unordered_map<int, int>U;//組み合わせiのときの最小値ｋ＋１
int b[26];
signed main() {
	U[0] = 1;
	string a; cin >> a;
	for (char c : a) {
		b[c-'a']++;
		int k = 0;
		for (int i = 0; i < 26; i++) {
			k *= 2;
			k += (b[i] & 1);
		}
		for (int i = 0; i < 26; i++) {
			int n = 0;
			for (int j = 0; j < 26; j++) {
				n *= 2;
				if(i!=j)n += (b[j] & 1);
				else n += (b[j] + 1) % 2;
			}
			if (U[n]) {
				if (U[k]) {
					U[k] = min(U[k], U[n] + 1);
				}
				else {
					U[k] = U[n] + 1;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < 26; i++) {
		k *= 2;
		k += (b[i] & 1);
	}
	cout << max(1ll,U[k] - 1) << endl;
}
