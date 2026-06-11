/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
 
#define rep(i, n) for(int i = 0; i < n; i++)
 
//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

int main()
{
	std::vector<bool> sosu(100005, true);
	// 前処理1 素数を100000までかぞえておく 
	sosu[0] = false;	// 0は素数ではない 
	sosu[1] = false;	// 1は素数ではない 
	for(int i = 2; i < 100005; i++)
	{
		for(int j = 2; i * j < 100005; j++ )
		{
			sosu[i*j] = false;
		}
	}

	// 前処理2 sosu[0]からsosu[i]までの2017に似た数の数をかぞえておく 
	std::vector<int> like_amt(100005, 0);
	int like_cnt = 0;
	for(int i = 1; i < 100005; i++)
	{
		if(i % 2 == 0)
		{
			like_amt[i] = like_cnt;
			continue;
		}
		if(sosu[i] == true)
		{
			if(((sosu[(i+1)/2])) == true)
			{
				like_cnt++;
			}
		}
		like_amt[i] = like_cnt;
	}
	// rep(i, 100)
	// {
	// 	std::cout << i << "(" << sosu[i] <<"):";
	// 	std::cout << like_amt[i] << std::endl;
	// }

	// 問題を解く 
	int Q;
	std::cin >> Q;
	std::vector<std::pair<int, int>> query(Q);
	rep(i, Q)
	{
		std::cin >> query[i].first >> query[i].second;
	}

	for(int i = 0; i < Q; i++)
	{
		ll ans = 0;
		int l, r;
		l = query[i].first; r = query[i].second;
		l--; r--;	// インデックスとして扱う 
		
		if(sosu[r+1] == true)
		{
			// printf("li");
			if(((sosu[(r+1+1)/2])) == true)
			{
				// printf("ke");
				ans++;
			}
		}
		
		ans += like_amt[r] - like_amt[l];
		
		std::cout << ans << std::endl;
	}

	return 0;
}