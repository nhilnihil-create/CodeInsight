#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	string s; cin >> s;
	deque<char> d;
	for (auto &e : s)
		d.push_back(e);

	ll res{0};
	while (d.size() > 1)
	{
		char f = d.front();
		char b = d.back();

		if (f == 'x' && b != 'x')
		{
			++res;
			d.push_back('x');
		}
		else if (f != 'x' && b == 'x')
		{
			++res;
			d.push_front('x');
		}

		f = d.front();
		b = d.back();
		if (f == b)
		{
			d.pop_front();
			d.pop_back();
		}
		else
		{
			res = -1;
			break;
		}
	}

	std::cout << res << std::endl;
}