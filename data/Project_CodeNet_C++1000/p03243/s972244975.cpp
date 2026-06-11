#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>

#include <set>
#include <bitset>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define endl '\n'
#define exit(s) return cout<<s,0;
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(), s.rend()
#define watch(x) cout << (#x) << " = " << x << endl
#define DNT ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll getbit(int num, int idx)
{
	return (num >> idx) & 1;
}
ll setbit(int num, int idx)
{

	return num || (1 << idx);
}
ll leastBit(ll num) {
	return (num & -num);
}
int main() {
	ll n, a, b, c,x;
	cin >> n;
	if (n < 10)
	{
		cout << n << endl;
		return 0;
	}
	for (int i = n;; i++)
	{
		x = i;
		a = x % 10;
		x = x / 10;
		b = x % 10;
		x = x / 10;
		c = x % 10;

		if (a == b && b == c)
		{
			cout << i << endl;
			break;
		}
		
	}
	return 0;
}

