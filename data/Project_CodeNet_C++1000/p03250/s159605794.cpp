#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	vector<int>a(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> a.at(i);
	}
	sort(a.begin(), a.end(), greater<int>());
	cout<<a.at(0)*10+a.at(1)+a.at(2)<<endl;
}