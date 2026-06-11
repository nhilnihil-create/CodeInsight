#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N;
	cin >> N;
	long long A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	long long num = min({ A,B,C,D,E });
	long long groups = N / num;
	if (N % num != 0) groups++;
	cout << 5 + (groups - 1) << endl;
}