#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

int maxtime(int x) {
	// Maximum consuming time for x-minute order
	return (x + 9) / 10 * 10;
}
int remtime(int x) {
	// Remained time for x-minute order
	return maxtime(x) - x;
}
int main() {
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	int sum = maxtime(A) + maxtime(B) + maxtime(C) + maxtime(D) + maxtime(E);
	sum -= max({ remtime(A), remtime(B), remtime(C), remtime(D), remtime(E) });
	cout << sum << endl;
	return 0;
}