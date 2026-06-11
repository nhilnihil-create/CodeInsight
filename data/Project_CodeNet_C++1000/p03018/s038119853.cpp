#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
#define int long long

string s;
int ans, h, x, y, n, s1[N];

signed main() {
	cin>>s;
	n = s.size();
	for(int i = 0; i < n; i++) {
		if(i) s1[i] = s1[i - 1];
		if(s[i] == 'A') s1[i]++;
	} 
	h = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') x = i;
		else {
			if(s[i] == 'B' && s[i + 1] == 'C') {
				y = i + 1;
				ans += s1[y];
				if(h) ans -= s1[h];
 				i++;
			}
			else 
				h = i;
		}
	}
	cout<<ans<<endl;
	return 0;
}