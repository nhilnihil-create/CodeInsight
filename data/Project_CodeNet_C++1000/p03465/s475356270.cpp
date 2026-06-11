#include<bits/stdc++.h>
#include<bitset>
using namespace std;

#define MAX 4000001

signed main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	int s = accumulate(v.begin(), v.end(), 0);
	bitset<MAX> bit;
	bit.reset();
	bit[0] = 1;
	for (int val : v)bit = bit | (bit << val);
	int i;
	for (i = (s + 1) / 2; i <= s; i++)if (bit[i])break;
	cout << i << endl;
}
