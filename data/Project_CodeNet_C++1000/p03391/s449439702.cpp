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
	long long int sum = 0;
	long long int rest = mod;
	for(int i = 0; i < n; i++){
		long long int a, b;
		cin >> a >> b;
		sum += a;
		if(a > b) rest = min(rest, b);
	}
	if(rest == mod) cout << 0 << endl;
	else cout << sum - rest << endl;
}