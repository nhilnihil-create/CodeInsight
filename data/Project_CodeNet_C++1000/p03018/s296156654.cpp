#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	long ans = 0, cnt = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') cnt++;
		else if(s[i] == 'B') {
			if(i + 1 < n && s[i+1] == 'C') {
				i++;
				ans += cnt;
			} else cnt = 0;
		} else cnt = 0;
	}
	printf("%ld\n", ans);
}
