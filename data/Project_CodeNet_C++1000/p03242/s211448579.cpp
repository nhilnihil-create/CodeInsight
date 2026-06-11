#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int n[1000];

int main()
{
	string n;
	cin >> n;
	int k = n.size();
	for (int i = 0; i < k; ++i)
	{
		cin >> n[i];
		if (n[i] == '1')
			n[i] = '9';
		else if (n[i] == '9')
			n[i] = '1';
	}
	cout << n;
}