#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t a, b;
	cin >> a >> b;
	int64_t gap = b - a;
	int64_t b_true = (1 + gap) * gap / 2;
	cout << b_true - b << endl;
}