#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string S;
	cin >> S;

	bool error = false;
	int cnt = 0;
	if (S.at(0) != 'A') error = true;
	int i = 1;
	while (!error && i < (int)(S.size())){
		if (!('a' <= S.at(i) && S.at(i) <= 'z')){
			if (S.at(i) == 'C' && 1 < i && i < (int)(S.size()) - 1) cnt++;
			else error = true;
		}
		i++;
		// cout << i << endl;
	}
	if (cnt != 1) error = true;
	if (error) cout << "WA" << endl;
	else cout << "AC" << endl;
}