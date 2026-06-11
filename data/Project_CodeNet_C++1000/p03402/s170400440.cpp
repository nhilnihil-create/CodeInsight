#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	const int h = 100;
	const int w = 100;
	vector<string> v(h);
	for (int i = 0; i < h / 2; ++i) {
		v[i].assign(w, '#');
		v[i + h / 2].assign(w, '.');
	}

	for (int i = 0; i < h / 2; i += 2) {
		for (int j = 0; j < w; j += 2) {
			if (A > 1) {
				v[i][j] = '.';
				--A;
			}
		}
		int k = h - 1 - i;
		for (int j = 0; j < w; j += 2) {
			if (B > 1) {
				v[k][j] = '#';
				--B;
			}
		}
	}

	cout << h << " " << w << endl;
	for (auto& s : v) {
		cout << s << endl;
	}
}
