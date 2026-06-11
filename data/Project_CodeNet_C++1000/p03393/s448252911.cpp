#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

string alp{"zyxwvutsrqponmlkjihgfedcba"};

int main(int argc, char **argv)
{
	string str; cin >> str;
	if (str == alp) {
		std::cout << -1 << std::endl;
		return 0;
	}

	ll N = (ll)str.size();
	set<char> s;
	for (auto &e : str)
		s.insert(e);

	string res{""};
	if (s.size() == 26)
	{
		ll i{0};
		for (; i < N;)
		{
			ll j = i + 1;
			while (j < N && str[j-1] > str[j]) {++j;}
			if (j == N) break;
			i = j;
		}

		// std::cout << "i : " << i<< std::endl;
		// std::cout << "s[i-1] : " << str[i-1] << std::endl;
		// std::cout << "right : " << str.substr(i, N-i) << std::endl;
		string right = str.substr(i-1, N-i+1);
		sort(right.begin(), right.end());
		char t;
		for (auto &c : right)
		{
			if (str[i-1] < c)
			{
				t = c;
				break;
			}
		}
		res = str.substr(0, i-1) + t;
	}
	else
	{
		char t;
		for (ll i = 0; i < 26; ++i)
		{
			if (!s.count(char('a'+i)))
			{
				t = (char)('a' + i);
				break;
			}
		}

		res = str + t;
	}
	std::cout << res << std::endl;
}
