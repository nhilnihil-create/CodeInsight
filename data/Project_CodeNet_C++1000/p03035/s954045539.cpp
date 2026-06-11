#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b;
	int mon;
	cin >> a >> b;
	if (a <= 5)
		mon = 0;
	else if (a >= 13)
		mon = b;
	else
		mon = b / 2;
	cout << mon << endl;
		
}