#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string s;
	cin >> s;
	int a, b;
	a = stoi(s);
	b = a % 100;
	a = (a - b) / 100;
	if ((a >= 1 && a <= 12) && (b >= 1 && b <= 12))
		cout << "AMBIGUOUS" << endl;
	else if (a >= 1 && a <= 12)
		cout << "MMYY" << endl;
	else if (b >= 1 && b <= 12)
		cout << "YYMM" << endl;
	else
		cout << "NA" << endl;


}
