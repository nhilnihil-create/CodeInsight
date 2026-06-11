#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	string s;
	bool flag = true, cCheck = false;
	cin >> s;
	
	if (s[0] != 'A') flag = false;
	
	for (int i = 2; i < (int)s.length() - 1; i++)
	{
		if (s[i] == 'C')
		{
			if (!cCheck) cCheck = true;
			else flag = false;
		}
	}

	int count = 0;
	rep(i, (int)s.length()) if (isupper(s[i])) count++;
	if (count != 2) flag = false;

	if(flag && cCheck) cout << "AC";
	else     cout << "WA";
	
	return 0;
}