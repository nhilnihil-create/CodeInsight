#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n,0);
	int sm=0;
	for(int i=0;i<n;i++)
	{
		cin >> a.at(i);
		sm+=a.at(i);
	}
    cout << sm - n << endl;
	return 0;
}
