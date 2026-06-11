#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ma, mi;
	ma = max(a, b);
	ma = max(ma, c);
	mi = min(a, b);
	mi = min(mi, c);
	cout << ma - mi << endl;
} 