#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0, before=0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == before) {
			ans++;
			before = 0;
		}
		else before = a;
	}
	cout << ans << endl;
}