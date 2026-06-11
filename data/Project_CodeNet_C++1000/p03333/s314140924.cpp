#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long n, l[100009], r[100009], sum;
vector<long long>D1, D2;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		D1.push_back(l[i]);
		D2.push_back(r[i]);
	}
	sort(D1.begin(), D1.end(), greater<long long>());
	sort(D2.begin(), D2.end());
	long long S = 0;
	for (int i = 0; i < n; i++) {
		sum = max({ sum,S,S + D1[i],S - D2[i],S + D1[i] - D2[i] });
		S += D1[i] - D2[i];
	}
	cout << sum * 2 << endl;
	return 0;
}