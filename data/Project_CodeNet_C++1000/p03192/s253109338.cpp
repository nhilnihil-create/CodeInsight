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
	cin >> s; int cnt = 0;
	rep(i, 4)
		if (s[i] == '2')cnt++;
	cout << cnt << endl;

	return 0;
}