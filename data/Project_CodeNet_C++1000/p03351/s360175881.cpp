#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((((a - b >= 0 && a - b <= d) || (b - a >= 0 && b - a <= d)) && ((c - b >= 0 && c - b <= d) || (b - c >= 0 && b - c <= d)))|| (c - a >= 0 && c - a <= d) || (a - c >= 0 && a - c <= d))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
} 