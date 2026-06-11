#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	double x,y;
	x = 1900*m + (n-m)*100;
	double p = pow(0.5,(double)m);
	y = x / p;
	cout<<y<<endl;
	return 0;
}

