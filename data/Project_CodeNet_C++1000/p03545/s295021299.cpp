#include"bits/stdc++.h"
using namespace std;

int main() {
	string s; cin >> s;
	vector<int> p(s.size());
	int n = s.size() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		p.at(i) = s.at(i) - '0';
	}
	for (int bit = 0; bit < (1<<n); bit++)
	{
		int sum = p.at(0);
		for (int i = 0; i < n; i++)
		{
			if((1<<i)&bit){
				sum += p.at(i + 1);
			}
			else {
				sum -= p.at(i + 1);
			}
		}
		if (sum == 7) {
			cout << p.at(0);
			for (int i = 0; i < n; i++)
			{
				if ((1 << i) & bit) {
					cout << '+' << p.at(i + 1);
				}
				else {
					cout << '-' << p.at(i + 1);
				}
			}
			cout << "=7" << endl;
			return 0;
		}
	}
}