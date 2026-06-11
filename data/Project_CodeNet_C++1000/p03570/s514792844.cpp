#include <bits/stdc++.h>
using namespace std;

int best[67108864];

int main(){
	string s;
	cin >> s;
	int n = (int)s.length();
	for(int i = 0; i<(1<<26); i++){
		best[i] = n+3;
	}
	best[0] = 0;
	int cur = 0;
	int ans = 0;
	for(int i = 0; i<n; i++){
		cur ^= (1<<((int)(s[i]-'a')));
		ans = best[cur]+1;
		for(int j = 0; j<26; j++){
			best[cur] = min(best[cur],best[cur^(1<<j)]+1);
			ans = min(ans,best[cur^(1<<j)]+1);
		}
	}
	cout << ans << endl;
}