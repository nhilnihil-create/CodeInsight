#include <iostream>
#include <cstdio>
using namespace std;

string s, t="keyence";
int cnt;
int main() {
	int i, j, k;
	cin >> s;
	for(i=0; s[i] && s[i]==t[i]; i++) cnt++;
	for(j=s.size()-1, k=6; j>i && s[j]==t[k]; j--, k--) cnt++;
	puts(cnt==7 ? "YES" : "NO");
	return 0;
}