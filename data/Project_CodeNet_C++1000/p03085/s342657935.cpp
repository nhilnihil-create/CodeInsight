#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using namespace std;

int  main()
{
	char b; cin >> b;
	map<char,char> mp;
	mp['A'] = 'T'; mp['T'] = 'A';
	mp['C'] = 'G'; mp['G'] = 'C';
	cout << mp[b] << endl;
	return (0);
}