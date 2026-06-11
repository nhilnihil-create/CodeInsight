#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> s(m);

	for (int i = 0; i < m; i++) {
		int kin;
		cin >> kin;
		k.at(i) = kin;
		for (int j = 0; j < kin; j++) {
			int sin;
			cin >> sin;
			s.at(i).push_back(sin);
		}
	}
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		int pin;
		cin >> pin;
		p.at(i) = pin;
	}
	
	int bit;
	int count = 0;
	vector<int> on(n);
	for (bit = 0; bit < (1 << n); bit++) {
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) on.at(i) = 1;
			else on.at(i) = 0;
		}
		// check if each light is turned on
		bool check = true;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int size = s.at(i).size();
			for (int j = 0; j < size; j++) {
				int idx = s.at(i).at(j) - 1;
				sum += on.at(idx);
			}
			if (sum % 2 != p.at(i)) {
				check = false;
				break;
			}
			sum = 0;
		}
		if (check) count++;
		
	}

	cout << count << endl;
	return 0;

}
