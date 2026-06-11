#include "bits/stdc++.h"
using namespace std;


int main() {
	int X;
	cin >> X;
	vector<int>Set;
	Set.push_back(1);
	for (int i = 2;i*i<=X;++i) {
		int tmp = i;
		while (tmp *i <=X) {
			tmp *= i;
			Set.push_back(tmp);
		}
	}
	sort(Set.rbegin(),Set.rend());
	cout << Set[0] << endl;
}
