//CODE FESTIVAL 2017 qual C
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(ll argc, char* argv[]) {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll changeStoneNumber = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='.')
		{
			changeStoneNumber++;
		}
	}
	ll answer = changeStoneNumber;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='.')
		{
			changeStoneNumber--;
		}
		else
		{
			changeStoneNumber++;
		}
		answer = min(answer,changeStoneNumber);
	}
	cout << answer << endl;
	return 0;
}