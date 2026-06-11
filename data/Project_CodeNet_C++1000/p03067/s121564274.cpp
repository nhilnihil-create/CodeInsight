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
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k = 0;
string s, t;



int main()
{
	cin >> a >> b >> c;
	if (c > a&& c < b)
		cout << "Yes" << endl;
	else if (c<a && c>b)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}