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
	int a, b, k;
	cin >> a >> b >> k;
	map<int, bool> check;

	rep(i, k)
	{
		if (a + i > b) break;
		check[a + i] = true;
		cout << a + i  << endl;
	}
	rep(i, k)
	{
		if (b - k + 1 +  i < a || check[b - k + 1 + i] != false) continue;
		cout << b - k + 1 + i << endl;
	}
	return 0;
}