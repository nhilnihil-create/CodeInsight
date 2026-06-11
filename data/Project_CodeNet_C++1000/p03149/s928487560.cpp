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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	set<int> s = { a, b, c, d }, ss = { 1, 9, 7, 4 };
	if (s == ss) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

