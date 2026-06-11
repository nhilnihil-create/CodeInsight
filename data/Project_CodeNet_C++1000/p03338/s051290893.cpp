#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;


int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 1;i < n;i++) {
		string a = s.substr(i);
		string b = s.substr(0, i);
		int cnt = 0;
		map<char, int> mp;
		rep(j, b.length()) {
			if (mp[b[j]] != 0) continue;
			mp[b[j]]++;
			rep(h, a.length()) {
				if (b[j] == a[h]) {
					cnt++;
					break;
				}
			}
		}ans = max(ans, cnt);
	}cout << ans;
}