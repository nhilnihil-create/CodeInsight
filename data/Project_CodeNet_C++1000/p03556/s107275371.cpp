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
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i*i <= n; i++) {
		ans = i * i;
	}
	cout << ans << endl;
	return 0;
}