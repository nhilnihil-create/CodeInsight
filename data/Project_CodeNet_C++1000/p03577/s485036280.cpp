#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	reverse(s.begin(), s.end());
	string ans = s.substr(8);
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;                                              
}
	
