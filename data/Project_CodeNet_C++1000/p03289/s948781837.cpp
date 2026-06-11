#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int way = 0;
	string s;
	cin >> s;
	if (s[0] == 'A')
	{
		++way;
	}
	int daiC = 0;
	for (int i = 2; i < s.size()-1; ++i)
	{
		daiC += (s[i] == 'C');
	}
	way += (daiC == 1);
	int ko = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ko += (s[i] >= 'a' && s[i] <= 'z');
	}
	way += (ko == s.size() - 2);
	cout << ((way == 3)?"AC":"WA") << endl;
	return 0;
}