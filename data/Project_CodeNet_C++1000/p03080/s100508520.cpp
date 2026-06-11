#include <iostream>
#include <cstdio>
using namespace std;

int n, cnt;
string s;
int main() {
	cin >> n >> s;
	for(int i=0; i<n; i++) s[i]=='R' ? cnt++ : cnt--;
	cout << (cnt>0 ? "Yes" : "No");
	return 0;
}