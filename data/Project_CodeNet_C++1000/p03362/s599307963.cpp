#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(55555 + 1, 1);
	a[0] = 0;
	a[1] = 0;
	for (int i = 2; i * i <= 55555; i++) {
		if (a[i] == 1)
			for (int j = i * 2; j <= 55555; j += i)
				a[j] = 0;
	}
	// 1が格納されているaの添え字(>=2)が素数
	vector<int> v;
	for (int i = 0; i <= 55555; i++)
		if (a[i] == 1)
			v.push_back(i);
	// 55555以下の素数
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 5 == 1) {
			cout << v[i] << " ";
			count++;
		}
		if (count == n)
			break;
	}
	cout << endl;
	return 0;
}