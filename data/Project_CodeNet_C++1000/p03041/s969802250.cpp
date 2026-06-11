#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	string S;
	cin >> S;
	S[K - 1] -= 'A' - 'a';
	cout << S << "\n";
	return 0;
}
