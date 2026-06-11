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

	string s;
	cin >> s;
	int ct = 0;
	if (s[0] == '2') ct++;
	if (s[1] == '2') ct++;
	if (s[2] == '2') ct++;
	if (s[3] == '2') ct++;
	cout << ct << "\n";

	return 0;
}

