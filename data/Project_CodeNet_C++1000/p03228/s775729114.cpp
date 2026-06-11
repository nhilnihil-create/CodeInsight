#ifdef __unix__
#include <bits/stdc++.h>
#else
#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>
#endif

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mkp make_pair
/*#define NUMTOSTR(x)  (unsigned char)((x) + 48);*/
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long  ull;
using namespace std;

int main(){
	fastIO;
	int a, b, n;
	cin >> a >> b >> n;
	bool t = true;
	while (n--)
	{
		if (t) {
			if (a & 1) a -= 1;
			b += a / 2;
			a /= 2;
		}
		else {
			if (b & 1) b -= 1;
			a += b / 2;
			b /= 2;
		}
		t ^= 1;
	}
	cout << a << ' ' << b;
	return 0;
}
