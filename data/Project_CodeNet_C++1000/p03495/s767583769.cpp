#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
5 2
1 1 2 2 5
0 1 2 3 4
0 2 2 0 0
*/

int main()	{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> freq(n + 1, 0);
	for (int i = 0; i < n; i++)	{
		cin >> a[i];
		freq[a[i]]++;
	}
	for (int i = 0; i < n + 1; i++)	if (freq[i] == 0) freq[i] = -1e9;
	sort(freq.begin(), freq.end(), greater<int>());
	long long int res = 0;
	for (int i = k; i < n; i++)	{
		res += max(freq[i], 0);
	}
	cout << res << endl;
	return 0;
}
