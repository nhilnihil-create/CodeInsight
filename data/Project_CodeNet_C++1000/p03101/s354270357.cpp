#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int h, w, h2, w2;
	cin >> h >> w >> h2 >> w2;
	int a,b;
	a = h * w;
	b = h2 * w + w2 * h - h2 * w2;
	cout << a - b << endl;
}