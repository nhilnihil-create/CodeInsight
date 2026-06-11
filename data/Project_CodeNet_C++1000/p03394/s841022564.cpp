#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> two, three, six;
	for (int i = 1; i <= 30000; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			six.push_back(i);
		}
		else if (i % 2 == 0 && i != 2 && i != 4)
		{
			two.push_back(i);
		}
		else if (i % 3 == 0 && i != 3 && i != 9)
		{
			three.push_back(i);
		}
	}
	vector<int> ans;
	if (n == 3)
	{
		cout << "2 5 63" << endl;
		return;
	}
	if (n == 4)
	{
		cout << "2 5 20 63" << endl;
		return;
	}
	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(4);
	ans.push_back(9);
	n -= 4;
	for (int i = 0; i < two.size()-1 && n >= 2; i += 2)
	{
		ans.push_back(two[i]);
		ans.push_back(two[i+1]);
		n -= 2;
	}
	for (int i = 0; i < three.size()-1 && n >= 2; i += 2)
	{
		ans.push_back(three[i]);
		ans.push_back(three[i+1]);
		n -= 2;
	}
	for (int i = 0; i < six.size() && n; i++)
	{
		ans.push_back(six[i]);
		n--;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << (i == ans.size()-1 ? '\n' : ' ');
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
