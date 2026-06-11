/* ***********************************************
Author        :pkwv
Created Time  :2017年10月22日 星期日 21时32分24秒
File Name     :D.cc
************************************************ */

#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
  std::string s;
	while (std::cin >> s) {
		std::vector<int> state(s.size() + 1);
		for (int i = s.size() - 1; i >= 0; -- i) {
			state[i] = state[i + 1] ^ (1 << (s[i] - 'a'));
		}
		std::unordered_map<int, int> dp;
		dp[0] = 0;
		for (int i = s.size() - 1; i >= 0; -- i) {
			int min_p(s.size());
			for (int j = 0; j < 26; ++ j) {
				int from_state(state[i] ^ (1 << j));
				auto iter = dp.find(from_state);
				if (iter != dp.end()) {
					min_p = std::min(min_p, iter->second + 1);
				}
			}
			if (dp.count(state[i])) {
				dp[state[i]] = std::min(dp[state[i]], min_p);
			} else {
				dp[state[i]] = min_p;
			}
		}
		std::cout << (dp[state[0]] ? dp[state[0]] : 1) << std::endl;
	}
  return 0;
}
