#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	// 全体から奇数になる組み合わせの数を引く
	// 3^10~O(1e5)なのでintで収まる
	int all = 1;
	int sub = 1;
	for (int i = 0; i < N; ++i)
	{
		all *= 3;
		int ai; cin >> ai;
		if (ai % 2 == 0) sub *= 2;
		else sub *= 1;
	}
	cout << all - sub << endl;
}
