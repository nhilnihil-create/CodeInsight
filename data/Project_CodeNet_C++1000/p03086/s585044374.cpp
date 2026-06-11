/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
 
//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

int main()
{
	std::string S;
	std::cin >> S;

	bool isOk = true;
	int ans = 0;
	int tmp = 0;
	for(char c : S)
	{
		if((c != 'A') && (c != 'C') && (c != 'T') && (c != 'G'))
		{
			isOk = false;
			tmp = 0;
		}
		else
		{
			isOk = true;
			tmp++;
		}
		ans = std::max(ans, tmp);
	}

	std::cout << ans << std::endl;

	return 0;
}