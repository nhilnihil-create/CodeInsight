#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	vector<int>a(5);
	int k;
	bool f = false;

	int i,j;
	for (i = 0; i < 5; i++)
	{
		cin >> a.at(i);
	}
	cin >> k;

	for (i = 0; i < 4; i++)
	{
		for (j = i; j < 5; j++)
		{
			if (a.at(j) - a.at(i) > k)
				f = true;
		}
	}
	if (f)
		cout << ":(" << endl;
	else
		cout << "Yay!" << endl;
}