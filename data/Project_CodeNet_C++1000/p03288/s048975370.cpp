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
#define sz(x) ((int)(x).size())
typedef long long ll;
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k = 0;
string s, t;


int main()
{
	cin >> n;
	if (n < 1200)
		cout << "ABC" << endl;
	else if (n < 2800)
		cout << "ARC" << endl;
	else
		cout << "AGC" << endl;
	
	return 0;
}