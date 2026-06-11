#include <iostream>
#include <cstdio>
using namespace std;

string s;
int ans;
int main() {
	cin >> s;
	for(int i=0; i<4; i++) if(s[i]=='2') ans++;
	cout << ans;
	return 0;
}