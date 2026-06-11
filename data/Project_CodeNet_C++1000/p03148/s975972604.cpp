#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

uint64_t K, N;

int main()
{
	vector<pair<uint64_t, uint64_t>> s;

	// データ読み込み
	cin >> N >> K;

	uint64_t a, b;

	for (uint64_t i = 0; i < N; i++)
	{
		cin >> a >> b;
		s.push_back(make_pair(b, a));
	}

	// value順に並び替え
	sort(s.begin(), s.end(), greater<>());

	// 暫定topを計算：種類MAXで最大のvalueを選択
	uint64_t c = 0;
	map<uint64_t, uint32_t> eat_kind;
	map<uint32_t, bool> eat;

	// 得点計算用
	uint64_t ans1 = 0;

	for (uint32_t i = 0; i < N; i++)
	{
		// すべて違う種類の寿司を食べる
		if (eat_kind.count(s[i].second) == 0)
		{
			ans1 += s[i].first;
			eat_kind[s[i].second] = 1;
			eat[i] = true;
			c++;
		}

		if (c >= K)
		{
			break;
		}
	}

	// c < Kの場合、価値の高いものをc>=Kとなるまで設定する
	for (uint32_t i = 0; i < N; i++)
	{
		if (c >= K)
		{
			break;
		}

		if (eat.count(i) == 0)
		{
			ans1 += s[i].first;
			eat_kind[s[i].second]++;
			eat[i] = true;
			c++;
		}
	}

	// valueの高いものを採用し、暫定topより高くなれば続ける。高くならなければEND
	uint64_t max_ans = ans1 + eat_kind.size() * eat_kind.size();
	uint64_t tmp_ans;
	for (uint32_t i = 0; i < N; i++)
	{
		if (eat.count(i) == 0)
		{
			ans1 = ans1 - s[eat.rbegin()->first].first + s[i].first;
			eat_kind[s[eat.rbegin()->first].second]--;
			if (eat_kind[s[eat.rbegin()->first].second] == 0)
			{
				eat_kind.erase(s[eat.rbegin()->first].second);
			}

			eat.erase(eat.rbegin()->first);
			eat[i] = true;
			tmp_ans = ans1 + eat_kind.size() * eat_kind.size();
			if (max_ans > tmp_ans)
			{
				break;
			}
			max_ans = tmp_ans;
		}
	}

	cout << max_ans << endl;
	return(0);
}