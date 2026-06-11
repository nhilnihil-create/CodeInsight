#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	if (x % y == 0)
		puts("-1");
	else
		cout << x << endl;
	return 0;
}