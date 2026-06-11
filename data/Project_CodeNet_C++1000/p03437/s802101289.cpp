#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

int a, b = 0,c, n, k;
string s, t;
//cout<<<<endl;


bool anagram(string s,string t)
{
	sort(all(s)); sort(all(t));
	if (s == t)
		return 1;
	else
		return 0;
}

int main()
{
	int64_t a, b;
	cin >> a >> b;
	if (a%b == 0)
		cout << -1 << endl;
	else
		cout << a << endl;
	return 0;
}
