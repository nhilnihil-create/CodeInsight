#include"bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	cout << (K <= (N + 1) / 2 ? "YES" : "NO") << endl;
	return 0;
}