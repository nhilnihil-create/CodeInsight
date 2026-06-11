#include <bits/stdc++.h>
using namespace std;

string ans = "";
string s,t,tmp = "";
int ls,lt,flag;

int main() {
	cin >> s >> t;
	ls = s.size();lt = t.size();
	if(ls < lt)  {
		puts("UNRESTORABLE");
		return 0;
	}
	for(int i = 0;i < ls - lt + 1;i++) {
		tmp = s;flag = 0;
		for(int j = i;j < i + lt;j++) {
			if(tmp[j] == '?') tmp[j] = t[j - i];
			else {
				if(tmp[j] != t[j - i]) {
					flag = 1;
					break;
				}
			}
		}
	//	cout << tmp << "\n";
		if(flag == 0) {
			for(int j = 0;j < ls;j++) {
				if(tmp[j] == '?') tmp[j] = 'a';
			}
			if(ans == "") ans = tmp;
			else ans = min(ans,tmp);
		}
	}
	if(ans != "") cout << ans << "\n";
	else puts("UNRESTORABLE");
	return 0;
}