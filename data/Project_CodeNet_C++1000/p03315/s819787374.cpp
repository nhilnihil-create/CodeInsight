#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
  
	int ans = 0;
  	for(int i = 0; i < s.length(); i++) {
      if(s[i] == '+') ans++;
      else ans--; //条件より'+'でなければ'-'なので引く
    }
  
  	cout << ans << endl;;
  	return 0;
}
