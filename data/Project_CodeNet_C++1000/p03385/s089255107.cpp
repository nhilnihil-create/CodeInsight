#include <iostream>
#include <cstdio>
#include <bitset>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define vec vector
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
	ll n;
	string s;
	ll count[3] = {0,0,0};

	cin >> s;

	forll(i, 0, 3)
	{
		if (s[i] == 'a')
			count[0]++;
		if (s[i] == 'b')
			count[1]++;
		if (s[i] == 'c')
			count[2]++;
	}
	
	if (count[0]==1 && count[1] == 1 && count[2] == 1)
		cout << "Yes";
	else
		cout << "No";
}