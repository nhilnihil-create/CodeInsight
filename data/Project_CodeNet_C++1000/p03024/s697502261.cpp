#include <bits/stdc++.h>

using namespace std;

char s[200];

int main() {
	cin >> s;
	int N;
	N = strlen(s);
	int maru = 0;
	for(int i=0;i<N;i++){
		maru += (s[i] == 'o');
	}
	maru += 15 - N;
	if(maru >= 8) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}