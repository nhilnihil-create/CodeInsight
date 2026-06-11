#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b;
	cin >> a >> b;
	int ans;
	if (a <= b)
		ans = a;
	else
		ans = a - 1;
	cout << ans << endl;
} 