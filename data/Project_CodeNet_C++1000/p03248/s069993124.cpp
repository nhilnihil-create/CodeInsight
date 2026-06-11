#include <iostream>
#include <cstdio>
using namespace std;

int n;
string s;
int main() {
	int i;
	cin >> s;
	n = s.size();
	s = '.' + s;
	if(s[1]!='1' || s[n]!='0') return puts("-1")*0;
	for(i=1; i<=n/2; i++) if(s[i] != s[n-i]) return puts("-1")*0;
	for(i=n-1; i; i--) {
		printf("%d %d\n", i, n);
		if(s[i]=='1') n = i;
	}
	return 0;
}