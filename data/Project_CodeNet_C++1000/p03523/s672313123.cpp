#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k = 0;
string s, t;



int main()
{
	cin >> s;
	if(s.size()>9)
	{
		cout << "NO" << endl; return 0;
	}
	int cnt = 0;
	rep(i, s.size() - 1)
	{
		if (s[i] == s[i + 1])
			cnt++;
		if (s[i] == 'K' && s[i + 1] == 'A')
			cnt++;
		if (s[i] == 'I' && s[i + 1] == 'A')
			cnt++;
	}
	if(cnt>0)
	{
		cout << "NO" << endl; return 0;
	}
	
	rep(i, s.size())
	{
		while (s[i] == 'A')
			s.erase(i, 1);
	}
	if (s == "KIHBR")
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}