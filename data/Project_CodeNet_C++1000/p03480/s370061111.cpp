#include <bits/stdc++.h>
using namespace std;
 
string s;
int ans = -1;
 
int main(){
	
	cin >> s;
   int ln = s.size();
	for (int i = 1; i < ln; i++) 
		if(s[i] != s[i - 1]) 
			if(ans== -1)
				ans= max(ln - i, i);
			else
				ans = min(ans, max(ln - i, i));
	if(ans == -1)
		cout << ln;
	else
		cout << ans; 
}