
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	string s;
	cin >> s;
	ll c = 0, c1 = 0;
	ll l = s.length();
	ll i = 0;
	while (i < l - 2)
	{
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
		{
			c1 += c + 1;
			s[i] = 'B';
			s[i + 1] = 'C';
			s[i + 2] = 'A';
			if (c > 0)
				i = i + 2;
		}
		else if (s[i] == 'A')
		{
			c++;
			i++;
		}
		else
		{
			c = 0;
			i++;
		}
	}
	cout << c1 << endl;



}
