
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void CodeFes2017FinalC();

int main()
{
	CodeFes2017FinalC();
	fflush(stdout);
	return 0;
}

static int cf2017fC_dfs(const std::vector<int>& di, int idx, std::vector<int>& times)
{
	int orgSize = times.size();

	int time = 0;
	if (idx > 12){
		int size = times.size();
		if (size > 1) {
			time = 36;
			for (int i = 0; i < size; i++) {
				for (int j = i + 1; j < size; j++) {
					int diff = abs(times[i] - times[j]);
					diff = std::min(diff, 24 - diff);
					time = std::min(time, diff);
				}
			}
		}
	}
	else {
		if (di[idx] == 1) {
			times.push_back(idx);
			time = cf2017fC_dfs(di, idx + 1, times);
			times.erase(times.begin() + orgSize, times.end());
			times.push_back(24 - idx);
			time = std::max(time, cf2017fC_dfs(di, idx + 1, times));
		}
		else if (di[idx] == 0) {
			time = cf2017fC_dfs(di, idx + 1, times);
		}
		else if (di[idx] == 2) {
			times.push_back(idx);
			times.push_back(24 - idx);
			time = std::max(time, cf2017fC_dfs(di, idx + 1, times));
		}
	}
	return time;
}

static void CodeFes2017FinalC()
{
	int N;
	getint(N);

	std::vector<int> di(13, 0);
	di[0] = 1;	//	高橋君
	for (int i = 0; i < N; i++) {
		int d;
		getint(d);
		di[d]++;
	}
	std::vector<int> times;
	int maxs = cf2017fC_dfs(di, 0, times);
	printf("%d\n", maxs);
}
