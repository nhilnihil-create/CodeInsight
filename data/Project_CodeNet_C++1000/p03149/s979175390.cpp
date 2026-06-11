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
	vector<int>n(4);
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	sort(all(n));
	if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}