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
	int odd = 0, even = 0;
	string s;
	cin >> s;

	//奇数番目に1が来る場合
	rep(i, s.length())
	{
		if (i % 2 != 0 && s[i] == '0') odd++;
		else if (i % 2 == 0 && s[i] == '1') odd++;
	}

	//偶数番目に1が来る場合
	rep(i, s.length())
	{
		if (i % 2 == 0 && s[i] == '0') even++;
		else if (i % 2 != 0 && s[i] == '1') even++;
	}

	cout << min(odd, even) << endl;
	return 0;
}