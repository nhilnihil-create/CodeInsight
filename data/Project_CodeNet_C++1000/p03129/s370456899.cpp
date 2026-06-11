#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,K;
	cin >> N >> K;
	cout << ((K <= N/2+N%2) ? "YES" : "NO") << endl;
}