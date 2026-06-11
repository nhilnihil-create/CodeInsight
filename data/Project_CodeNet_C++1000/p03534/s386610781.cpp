#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
	string s; cin >> s;
	int count[3] = {};
	for(int i = 0; i < s.size(); ++i) ++count[s[i] - 'a'];
	int m = 1e5+1;
	for(int i = 0; i < 3; ++i) m = min(m, count[i]);
	for(int i = 0; i < 3; ++i) count[i] -= m;
	int po = 0;
	for(int i = 0; i < 3; ++i){
		if(count[i] == 1) ++po;
		else if(count[i] > 1) po += 3;
	}
	cout << (po >= 3 ? "NO\n" : "YES\n");
	return 0;
}