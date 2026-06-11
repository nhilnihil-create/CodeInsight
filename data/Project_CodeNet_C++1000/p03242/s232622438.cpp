#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string n;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		if (n.at(i) == '1')
			n.at(i) = '9';
		else if (n.at(i) == '9')
			n.at(i) = '1';
	}
	cout << n << endl;
}