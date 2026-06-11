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
	string s, t;
	cin >> s >> t;
	rep(i, s.length())
	{
		string temp = s.substr(i, s.length() - i) + s.substr(0, i);
		if (temp == t)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}