#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	string s;
	int K;
	cin >> s >> K;
	set<string>se;
	for (char c = 'a'; c <= 'z'; c++) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c) {
				string tmp;
				tmp = c;
				se.insert(tmp);
				for (int j = i + 1; j < s.size(); j++) {
					if (j - i >= K)break;
					tmp += s[j];
					se.insert(tmp);
				}
			}
		}
		if (se.size() >= K)break;
	}
	int cnt = 0;
	for (auto i : se) {
		cnt++;
		if (cnt == K) {
			cout << i << endl;
			return 0;
		}
	}
}