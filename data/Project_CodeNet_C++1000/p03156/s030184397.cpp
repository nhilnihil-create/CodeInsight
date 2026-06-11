#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int a, b, c;
	a = 0; b = 0; c = 0;

	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		if (P <= A) a++;
		else if (P <= B) b++;
		else c++;
	}

	cout << min(min(a, b), c) << endl;
}