#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int N, T, A;
	vector<int> vec(1100);

	cin >> N;
	cin >> T >> A;
	double min = 1e5;
	int min_idx = -1;
	double diff;

	rep(i, N)
	{
		cin >> vec.at(i);
		diff = abs(A - (T - vec.at(i) * 0.006));
		if (diff < min)
		{
			min_idx = i + 1;
			min = diff;
		}
	}
	cout << min_idx << endl;

	return 0;
}