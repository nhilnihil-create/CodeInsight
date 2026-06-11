#include <bits/stdc++.h>
using namespace std;
int main(){
	string s, a; cin >> s;
	int w; cin >> w;
	for(int i = 0; i < s.size(); i += w) a.push_back(s[i]);
	cout << a << endl;
	return 0;
}
