#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B;
	cin >> A >> B;

	int cnt = 0;
	for (int i = A; i <= B; i++) {
		string s = to_string(i);
		if ((s.at(0) == s.at(4)) && (s.at(1) == s.at(3))) cnt++;
	}

	cout << cnt << endl;
}