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
	ll n, lucas_before = 2, lucas_after = 1;
	cin >> n;

	if (n == 0) 
	{
		cout << lucas_before << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << lucas_after << endl;
		return 0;
	}
	rep(i, n - 2)
	{
		ll temp = lucas_before + lucas_after;
		lucas_before = lucas_after;
		lucas_after = temp;
	}

	cout << lucas_before + lucas_after << endl;
	return 0;
}