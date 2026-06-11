#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++) cin >> A[i];
	int even = 0;
	for(int i = 0; i < N; i++)
		if(A[i] % 2 == 0) even++;
	cout << pow(3, N) - pow(2, even) << "\n";
	return 0;
}