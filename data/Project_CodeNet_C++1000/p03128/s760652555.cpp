// 118_D_Match_Matching.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include <fstream>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int takeMatches(int i, int n, int baseWeight, vector<int> counts, vector<int> nums, vector<int> &dp)
{
	if (i >= nums.size()) return -1;

	int x = nums[i];
	int c = counts[x] - baseWeight;
	int d = n / c;
	int r = 0;

	if (x >= nums[0])
	{
		for (int j = d; j >= 0; j--)
		{
			dp[x] = j;
			//数字iをj個作った場合のマッチのあまり。
			r = n - c * j;

			//マッチを取りつくせた場合は終了。
			//その時の各数字の個数が答え。
			if (r == 0) return 0;

			//再帰
			r = takeMatches(i + 1, r, counts[nums[0]], counts, nums, dp);
			if (r == 0) return 0;;
		}
	}
	else
	{
		for (int j = 0; j <= d; j++)
		{
			dp[x] = j;
			//数字iをj個作った場合のマッチのあまり。
			r = n - c * j;

			//マッチを取りつくせた場合は終了。
			//その時の各数字の個数が答え。
			if (r == 0) return 0;

			//再帰
			r = takeMatches(i + 1, r, counts[nums[0]], counts, nums, dp);
			if (r == 0) return 0;;
		}
	}
	

	return r;
}


int main()
{
	//std::ifstream in("C:\\Users\\Owner\\Desktop\\D\\in\\0_random_3");
	//std::cin.rdbuf(in.rdbuf());

	vector<int> counts = {6,2,5,5,4,5,6,3,7,6};

	int n, m;
	cin >> n >> m;

	priority_queue<int> pq[10];
	rep(i, m)
	{
		int tmp;
		cin >> tmp;

		pq[counts[tmp]].push(tmp);
	}

	//使うマッチの数が同じで数値が最も大きいもののみ使用
	vector<int> num;
	rep(i, 10)
	{
		if (!pq[i].empty())
		{
			num.push_back(pq[i].top());
		}
	}

	sort(num.begin(), num.end(), greater<int>());
	
	vector<int> dp(10);
	rep(i, 10)
	{
		if (pq[i].empty()) continue; 

		vector<int> num2;
		int x = pq[i].top();
		num2.push_back(x);
		for (int y : num)
		{
			if (y == x) continue;

			num2.push_back(y);
		}

		fill(dp.begin(), dp.end(), 0);
		if (takeMatches(0, n, 0, counts, num2, dp) == 0)
		{
			rep(j, 10)
			{
				if (j == x) continue;
				dp[x] -= dp[j];
			}
			break;
		}
	}


	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < dp[i]; j++)
		{
			cout << i;
		}
	}


	return 0;
}