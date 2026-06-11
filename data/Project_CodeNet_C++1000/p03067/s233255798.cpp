#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if ((c >= a) && (c <= b)) cout << "Yes";
	else if ((c >= b) && (c <= a)) cout << "Yes";
	else cout << "No";

	return 0;
}

