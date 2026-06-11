#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,t;
	cin >> s;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s.at(i)!='x')
		{
			t += s.at(i);
		}
	}
	for (size_t i = 0; i < t.size()/2; i++)
	{
		if (t.at(i)!=t.at(t.size()-1-i))
		{
			cout << -1;
			return 0;
		}
	}
	vector<int> spot(t.size() + 1);
	int chking = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (chking<t.size()&&s.at(i)==t.at(chking))
		{
			chking++;
		}
		else
		{
			spot.at(chking)++;
		}
	}
	int ans=0;
	for (size_t i = 0; i < spot.size()/2; i++)
	{
		ans += abs(spot.at(i) - spot.at(spot.size() - 1 - i));
	}
	cout << ans;
}
