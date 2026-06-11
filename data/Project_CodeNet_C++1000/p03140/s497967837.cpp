#include <bits/stdc++.h>

using namespace std;

int op(char a, char b, char c){
	if (a == b && b == c) return 0;
	if (a != b && b != c && c != a) return 2;
	return 1;
}

int main(void){
	int N; cin >> N;
	string A, B, C; cin >> A >> B >> C;
	int res = 0;
	for (int i = 0; i < N; ++i)
		res += op(A[i], B[i], C[i]);
	cout << res << endl;
	return 0;
}