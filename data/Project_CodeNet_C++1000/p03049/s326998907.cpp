#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	int ans = 0;
	int backANum = 0, frontBNum = 0, frontBbackANum = 0;
	REP(i, N)
	{
		string s; cin >> s;
		REP(j, s.length() - 1)
		{
			if (s[j] == 'A' && s[j + 1] == 'B') ++ans;
		}
		if (s.front() == 'B') {
			if (s.back() == 'A') ++frontBbackANum;
			else ++frontBNum;
		}
		else if (s.back() == 'A') ++backANum;
	}
	if (frontBbackANum == 0)
	{
		ans += min(frontBNum, backANum);
	}
	else if(frontBNum + backANum != 0)
	{
		ans += frontBbackANum + min(frontBNum, backANum);
	}
	else
	{
		ans += frontBbackANum - 1;
	}
	cout << ans << endl;
}