#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	vector<string>s(n);
	vector<int>p(n);
	int r[105] = { 0 };
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> s.at(i) >> p.at(i);
		r[i]++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (s.at(i) > s.at(j))
			{
				//cout << ":" << i << " " << j << endl;
				r[i]++;
			}
			else if (s.at(i) == s.at(j))
			{
				if (p.at(i) < p.at(j))
					r[i]++;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == r[j])
				cout << j+1 << endl;
		}
	}
}