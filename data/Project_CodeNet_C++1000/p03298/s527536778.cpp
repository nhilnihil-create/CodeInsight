#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;
map<pss, int> mp;


long long ans, n;
string s;
int main() {
	cin >>n >> s;
	int mid = (int)s.size() / 2, mid2 = (int)s.size() - mid;
	for (int i = 0; i < (1<<mid); i++) {
		string s1, t1;
		for (int j = 0; j < mid; j++) {
			if ((i>>j) & 1) 
				s1 += s[j];
			else 
				t1 += s[j];
		}
		reverse(t1.begin(), t1.end());
		mp[pss(s1, t1)]++;
	}
	for (int i = 0; i < (1<<mid2); i++) {
		string s1, t1;
		for (int j = 0; j < mid2; j++) {
			if ((i>>j) & 1) 
				s1 += s[j+mid];
			else 
				t1 += s[j+mid];
		}
		reverse(s1.begin(), s1.end());
		ans += mp[pss(s1, t1)];
		
	}
	cout << ans;
}