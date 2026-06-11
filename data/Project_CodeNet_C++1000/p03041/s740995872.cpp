#include <bits/stdc++.h>
using namespace std;

signed main(){
	int N, K;
	scanf("%d%d", &N, &K);
	string S;
	cin >> S;
	S[K - 1] += 'a' - 'A';
	cout << S << endl;
	return 0;
}