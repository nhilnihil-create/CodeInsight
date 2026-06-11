#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p[1 << 26], c[200009], a[26]; string S;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		a[S[i] - 'a'] ^= 1;
		for (int j = 0; j < 26; j++) c[i + 1] += (a[j] << j);
	}
	for (int i = 0; i < (1 << 26); i++) p[i] = (1 << 30);
	p[0] = 0;
	for (int i = 1; i <= S.size(); i++) {
		for (int j = 0; j < 26; j++) {
			int T = c[i];
			if ((c[i] / (1 << j)) % 2 == 0) T += (1 << j);
			else T -= (1 << j);
			p[c[i]] = min(p[c[i]], p[T] + 1);
		}
	}
	cout << max(1, p[c[S.size()]]) << endl;
	return 0;
}