#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<string>A(3);
	for (int i = 0; i < 3; i++) cin >> A.at(i);
	int ans = 0, ch = 0;
	for (int i = 0; i < N; i++) {
		if (A[0].at(i) != A[1].at(i))ch++;
		if (A[1].at(i) != A[2].at(i)) ch++;
		if (A[0].at(i) != A[2].at(i)) ch++;
		if (ch == 3) ans += 2;
		else ans += min(ch, 3 - ch);
		ch = 0;
	}
	cout << ans << endl;
}