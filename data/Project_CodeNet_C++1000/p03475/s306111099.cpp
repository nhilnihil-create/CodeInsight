#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	vector<int> cs(N - 1), ss(N - 1), fs(N - 1);
	for (int i = 0; i < N - 1; ++i) cin >> cs[i] >> ss[i] >> fs[i];
	for (int s = 0; s < N; ++s)
	{
		int ans = 0;
		for (int i = s; i < N - 1; ++i)
		{
			if (ans / fs[i] < ss[i] / fs[i])
			{
				ans = ss[i] + cs[i];
			}
			else
			{
				if (ans % fs[i] == 0)
				{
					ans = ans + cs[i];
				}
				else
				{
					ans = (ans / fs[i] + 1) * fs[i] + cs[i];
				}
			}
		}
		cout << ans << endl;
	}
}