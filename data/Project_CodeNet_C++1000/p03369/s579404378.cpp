#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int ans = 700;
	for (int i = 0; i < 3; i++)
	{
		char s;
		cin >> s;
		if (s == 'o')
			ans += 100;
	}
	cout << ans << endl;
} 