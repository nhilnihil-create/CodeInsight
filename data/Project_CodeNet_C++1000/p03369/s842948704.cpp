#include <bits/stdc++.h>
using namespace std;

signed main(){
	string S;
	cin >> S;
	printf("%d\n", 700 + 100 * ((S[0] == 'o') + (S[1] == 'o') + (S[2] == 'o')));
	return 0;
}