#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> a(N);
	cout << 0 << endl;
	cin >> a.front();
	cout << N - 1 << endl;
	cin >> a.back();
	if (a.front() != "Vacant" && a.back() != "Vacant") {
		pair<int, int> b{ 0, N };
		while (true) {
			cout << (b.first + b.second) / 2 << endl;
			cin >> a[(b.first + b.second) / 2];
			if (a[(b.first + b.second) / 2] == "Vacant") break;
			if (a[b.first] == a[(b.first + b.second) / 2]) {
				if (((b.first + b.second) / 2 - b.first) % 2) b.second = (b.first + b.second) / 2;
				else b.first = (b.first + b.second) / 2;
			}
			else {
				if (((b.first + b.second) / 2 - b.first) % 2) b.first = (b.first + b.second) / 2;
				else b.second = (b.first + b.second) / 2;
			}
		}
	}
}