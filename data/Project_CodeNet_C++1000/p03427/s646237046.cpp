#include <iostream>
#include <string>
using namespace std;

int numberSize(string N) {
	int sum = 0;
	for (int i = 0; i < (int)N.size(); i++) {
		sum += N[i] - '0';
	}
	return sum;
}

int main() {
	string N; cin >> N;
	int sum = numberSize(N);
	int Max = N[0] - '0' + 9 * ((int)N.size() - 1);
	if (sum == Max) cout << sum << endl;
	else cout << Max - 1 << endl;
}