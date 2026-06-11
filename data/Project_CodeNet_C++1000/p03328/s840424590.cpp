#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long int ll;


int main()
{
	ll a, b;
	cin >> a >> b;
	ll diff = b - a;
	ll sum = 0;
	for (ll i = 1; i <= (diff - 1); i++) {
		sum += i;
	}
	cout << sum - a << endl;
	return 0;
}