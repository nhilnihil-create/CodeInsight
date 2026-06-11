#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

uint64_t K, N;

struct sushi
{
	uint64_t kind;
	uint64_t value;
	bool use_flag;

	sushi(uint64_t k, uint64_t v)
	{
		kind = k;
		value = v;
		use_flag = false;
	}

	bool operator<(const sushi &another) const
	{
		return value < another.value;
	}

	bool operator>(const sushi &another) const
	{
return value > another.value;
	}

};

int main()
{
	uint64_t max_ans = 0;
	vector<sushi> s;

	// データ読み込み
	cin >> N >> K;

	uint64_t a, b;

	for (uint64_t i = 0; i < N; i++)
	{
		cin >> a >> b;
		s.push_back(sushi(a, b));

	}

	// value順に並び替え
	sort(s.begin(), s.end(), greater<>());

	// 暫定topを計算：種類MAXで最大のvalueを選択
	uint64_t c = 0;
	map<uint64_t, bool> eat_kind;
	vector<uint64_t> eat;

	for (uint64_t i = 0; i < N; i++)
	{
		// すべて違う種類の寿司を食べる
		if (eat_kind.find(s[i].kind) == eat_kind.end())
		{
			s[i].use_flag = true;
			eat_kind[s[i].kind] = true;
			eat.push_back(i);
			c++;
		}

		if (c >= K)
		{
			break;
		}
	}

	// c>=Kの場合、価値の高いものをc>=Kとなるまで設定する
	for (uint64_t i = 0; i < N; i++)
	{
		if (s[i].use_flag == false)
		{
			s[i].use_flag = true;
			eat.push_back(i);
			c++;
		}

		if (c >= K)
		{
			break;
		}
	}
	sort(eat.begin(), eat.end());
	// max_ans = eval_oishisa(s, eat);

	// 得点計算
	uint64_t ans1 = 0;
	map<uint64_t, uint32_t> kind;

	for (auto itr = eat.begin(); itr != eat.end(); itr++)
	{
		ans1 += s[*itr].value;
		if (kind.count(s[*itr].kind) == 0)
		{
			kind[s[*itr].kind] = 1;
		}
		else
		{
			kind[s[*itr].kind]++;
		}

	}
	max_ans = ans1 + kind.size() * kind.size();

	// valueの高いものを採用し、暫定topより高くなれば続ける。高くならなければEND
	uint64_t tmp_ans = 0;
	for (uint64_t i = 0; i < N; i++)
	{
		if (s[i].use_flag == false)
		{
			s[i].use_flag = true;
			s[eat.back()].use_flag = false;
			ans1 = ans1 - s[eat.back()].value + s[i].value;
			kind[s[eat.back()].kind]--;
			if (kind[s[eat.back()].kind] == 0)
			{
				kind.erase(s[eat.back()].kind);
			}

			eat.pop_back();
			eat.insert(eat.begin(), i);
			// eat.push_back(i);
			// sort(eat.begin(), eat.end());
			// tmp_ans = eval_oishisa(s, eat);
			tmp_ans = ans1 + kind.size() * kind.size();
			if (max_ans > tmp_ans)
			{
				break;
			}
			max_ans = tmp_ans;
		}
	}

	cout << max_ans << endl;
}