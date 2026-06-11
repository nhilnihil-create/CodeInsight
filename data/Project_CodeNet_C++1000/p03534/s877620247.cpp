#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(ll i=0;i<n;i++)
#define ll long long
#define double long double
#define pi 3.141592653589
using namespace std;
ll cnt[26];
signed main() {
	string s;
	cin >> s;
	rep(i, s.size())cnt[s[i] - 'a']++;
	rep(i, 26) {
		if ((s.size() - 1) / 3 + 1 < cnt[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	getchar(); getchar(); return 0;
}