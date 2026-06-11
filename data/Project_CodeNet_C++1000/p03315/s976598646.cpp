#include <bits/stdc++.h>
using namespace std;

string s;
char c;
int cnt = 0;

int main () {
	cin >> s;
	for (int i = 0; i<4; i++){
		c = s[i];
		if(c ==43){
			cnt++;
		} else if (c ==45){
			cnt--;
		}
	}
	cout << cnt;
}