#include <iostream>
#include <cstdio>
using namespace std;

string s = "ACGT";
char x;
int main() {
	int i;
	cin >> x;
	for(i=0; i<4; i++) if(s[i]==x) break;
	cout << s[3-i];
	return 0;
}
