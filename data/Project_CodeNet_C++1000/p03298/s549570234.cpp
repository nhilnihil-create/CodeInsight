#include <iostream>
#include <stdint.h>
#include <string>
#include <utility>
#include <map>
#include <algorithm>

using namespace::std;

int main()
{
	int N;
	cin >> N;

	string str;
	cin >> str;

	map<pair<string, string>, int> mp;
	map<pair<string, string>, int> mq;

	for (int i = 0; i < (1 << N); i++)
	{
		string u = "";
		string v = "";

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
				u.push_back(str[j]);
			else
				v.push_back(str[j]);
		}

		reverse(v.begin(), v.end());
		mp[make_pair(u, v)]++;
	}

        for (int i = 0; i < (1 << N); i++)
        {
                string u = "";
                string v = "";

                for (int j = 0; j < N; j++)
                {
                        if (i & (1 << j))
                                u.push_back(str[N + j]);
                        else
                                v.push_back(str[N + j]);
                }
		
		reverse(v.begin(), v.end());
		mq[make_pair(v, u)]++;
        }

	int64_t ans = 0;
	for (map<pair<string, string>, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		pair<string, string> s = it->first;
		int64_t x = it->second;
		int64_t y = mq[s];

		ans += x * y;
	}

	cout << ans << endl;

	return 0;
}
