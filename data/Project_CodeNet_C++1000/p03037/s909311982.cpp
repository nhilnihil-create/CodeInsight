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
	int n, m;
	cin >> n >> m;
	int first = 0, last = n + 1;
	rep(i, m)
	{
		int l, r;
		cin >> l >> r;
		first = max(l, first);
		last = min(r, last);
	}
	if (first <= last) cout << last - first + 1 << endl;
	else cout << 0 << endl;
	return 0;
}