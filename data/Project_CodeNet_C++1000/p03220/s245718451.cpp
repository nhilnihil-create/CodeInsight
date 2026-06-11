#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979


int main()
{
	int n, bestSpot = -1;
	double t, a, bestDistance = 10101010.0;
	cin >> n >> t >> a;
	
	rep(i, n)
	{
		double h;
		cin >> h;
		if (abs(a-(t - h * 0.006)) < bestDistance)
		{
			bestDistance = abs(a - (t - h * 0.006));	//最小値を記録
			bestSpot = i + 1;		  //最有力候補のインデックスを記録
		}
	}
	cout << bestSpot;
	return 0;
}