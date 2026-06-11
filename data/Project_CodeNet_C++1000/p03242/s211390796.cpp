#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
	string s;
	cin >> s;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '1')
		{
			s[i]='9';
		}
		else if(s[i] == '9')
		{
			s[i] = '1';
		}
	}
	cout << s << endl;
return 0;
}
