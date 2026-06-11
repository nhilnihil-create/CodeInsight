#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>


using namespace std;

long long x, y;
int main()
{
	cin >> x >> y;
	if (x % y == 0)
	{
		cout << -1;
	}
	else
	{
		cout << x << endl;
	}

}
