#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	string S;
	ll K;

	cin >> S >> K;

	char ans = '1';
	for (int i = 0; i < S.size() && i < K; ++i)
	{
		if (S[i] != '1')
		{
			ans = S[i];
			break;
		}
	}

	cout << ans << endl;
	
	return 0;
}