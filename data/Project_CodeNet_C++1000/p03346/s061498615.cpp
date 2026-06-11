#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	int res[200001] = {};
	int maxRes = 0;
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		p--;
		res[p] = 1;
		if(p > 0) res[p] += res[p - 1];
		maxRes = max(maxRes, res[p]);
	}
	cout << n - maxRes << endl;
}