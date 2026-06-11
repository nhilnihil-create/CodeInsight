#include <bits/stdc++.h>
using namespace std;

signed main(){
	string s; cin >> s;
	int n = s.size();
	int num = s[0] - '0';
    bool check = false;
    for(int i = 1; i < n; i++) if(s[i] != '9') check = true;
	if(check) cout << num + 9 * (n - 1) - 1 << endl;
  else cout << num + 9 * (n -1) << endl;
}
