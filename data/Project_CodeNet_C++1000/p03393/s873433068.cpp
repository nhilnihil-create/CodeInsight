#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

signed main(void) {
	string s;
	cin >> s;
	if (s.size() != 26) {
		map<char, int>mp;
		rep(i, s.size()) {
			mp[s[i]]++;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (mp[c] == 0) {
				print(s + c);
				return 0;
			}
		}
	}
	else if (s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
		return 0;
	}
	else {
		int ansindex = 0;
		map<char, int>mp2;
		rrep(i, 25) {
			if (s[i] < s[i + 1]) {
				ansindex = i+1;
				break;
			}
		}
		string ans;
		rep(i, ansindex) {
			mp2[s[i]]++;
			ans += s[i];
		}
		//println(ans);
		for (char c = 'a'; c <= 'z'; c++) {
			if (mp2[c] == 0 && ans[ansindex-1]<c) {
				ans[ansindex-1]=c;
				println(ans);
				return 0;
			}
		}
	}
}