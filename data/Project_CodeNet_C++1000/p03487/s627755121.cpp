#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main()	{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++)	{
		cin >> a[i];
		freq[a[i]]++;
	}
	int res = 0;
	for (auto x : freq)	{
		if (x.first > x.second)	{
			res += x.second;
		}
		else if (x.first < x.second)	{
			res += (x.second - x.first);
		}
	}
	cout << res << endl;
	return 0;
}
