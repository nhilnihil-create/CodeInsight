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
	int N;
	vector<ll> vec(110);

	ll min = 1e9;
	ll max = 1;
		
	cin >> N;
	rep(i, N) { cin >> vec.at(i); }

	rep(i, N)
	{
		if (vec.at(i) > max) { max = vec.at(i); }
		if (vec.at(i) < min) { min = vec.at(i); }
	}

	cout << max - min << endl;
	return 0;
}