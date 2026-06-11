#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char const* argv[]) {
	int N;
	scanf("%d", &N);
	string S[100];
	set<string> arare;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		// cout << S[i] << endl;
		arare.insert(S[i]);
	}
	// cout << arare.size() << endl;
	printf(arare.size() == 4 ? "Four\n" : "Three\n");

	return 0;
}
