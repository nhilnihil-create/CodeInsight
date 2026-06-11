#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define all(x) x.begin(), x.end()

signed main() {
	string s;
	cin >> s;
	int ans = 0;
	int cou=0;
	rep(i, s.size()){
		if(s[i] == 'A' || s[i] == 'C'||s[i]=='G'||s[i]=='T'){
			cou++;
			ans = max(ans, cou);
		}
		else cou = 0;
	}
	cout << ans << endl;
	
	return 0;			
}