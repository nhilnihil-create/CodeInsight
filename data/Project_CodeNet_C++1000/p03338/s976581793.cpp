#include<bits/stdc++.h>
using namespace std;
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	repn(i, 1, n - 1){
		vector<char> v(26, 0);
		rep(j, i) v[s[j] - 'a'] = 1;
		int cur = 0;
		repn(j, i, n) if(v[s[j] - 'a']) cur++, v[s[j] - 'a']--;
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}