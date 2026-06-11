#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
	string s;
	cin >> s;
	
	int ctn = 0;
	rep(i, 3){
		if(s[i] == 'o'){
			ctn++;
		}
	}
	
	cout << 700 + ctn * 100 << endl;
	
}