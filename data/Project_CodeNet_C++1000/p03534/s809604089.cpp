#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt[3] = {};
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++) cnt[s[i] - 'a']++;
	int ma = max({cnt[0],cnt[1],cnt[2]}),mi = min({cnt[0],cnt[1],cnt[2]});
	if(mi + 1 >= ma) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}