#include <iostream>
#include <cstdio>
#define NO return puts("NO")*0
using namespace std;

string s;
int main() {
	cin >> s;
	int i=0;
	if(s[i]=='A') i++;
	if(s[i]=='K') i++; else NO;
	if(s[i]=='I') i++; else NO;
	if(s[i]=='H') i++; else NO;
	if(s[i]=='A') i++;
	if(s[i]=='B') i++; else NO;
	if(s[i]=='A') i++;
	if(s[i]=='R') i++; else NO;
	if(s[i]=='A') i++;
	puts(i==s.size() ? "YES" : "NO");
	return 0;
}