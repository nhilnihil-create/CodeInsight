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
	int n;
	char before = ' ';
	map<string, bool> word;
	cin >> n;

	rep(i, n)
	{
		string s;
		cin >> s;
		if (before != ' ' && s[0] != before || word[s] != false)
		{
			cout << "No";
			return 0;
		}
		before = s[s.length() - 1];
		word[s] = true;
	}
	cout << "Yes";
	return 0;
}