#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	string s; cin >> s;
	string t;
	for(lint i = 0; i < s.size(); i++){
		if(s[i] == 'B' && s[i + 1] == 'C'){
			t.push_back('D');
			i++;
		}
		else{
			t.push_back(s[i]);
		};
	}
	lint ans = 0, counter = 0;
	for(lint i = 0; i < t.size(); i++){
		if(t[i] == 'A') counter++;
		else if(t[i] == 'D') ans += counter;
		else counter = 0;
	}
	cout << ans << endl;
}