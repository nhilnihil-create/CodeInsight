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
	int count = 0;
	int n_500, n_100, n_50, x;
	cin >> n_500 >> n_100 >> n_50 >> x;

	rep(i, n_500+1)rep(j, n_100+1)rep(k, n_50+1)
	{
		if ((i * 500 + j * 100 + k * 50) == x) count++;
	}

	cout << count << endl;
	return 0;
}