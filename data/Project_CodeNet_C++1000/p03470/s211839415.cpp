#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int count = 1;
	int under;
	
	cin >> n;

	vector<int> data(n);

	for (int i = 0; i < n; i++)
		cin >> data.at(i);

	sort(data.begin(), data.end(), greater<int>());

	under = data.at(0);

	for (int i = 1; i < data.size(); i++) {
		if (under > data.at(i)) {
			under = data.at(i);
			count++;
		}
	}

	cout << count << endl;

}