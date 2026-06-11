#pragma GCC optimize(2)
#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include<cstring>
#include <stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include <string>
#define itn int
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
const int maxn = 2000 * 100 + 6;
const int maxa = 1000 * 1000 * 1000 + 7;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int t, n, m, T;
int a[maxn];


int f(int l, int r) {
	//return (r - l) * (r - l - 1) / 2 + r - l;
	return (r - l);
}
int main()
{
#ifdef _DEBUG
	freopen("D:\\input.txt", "r", stdin);
	//	freopen("E:\\output.txt", "w", stdout);
#endif
	int i, j;
	
	std::ios::sync_with_stdio(false); cin.tie(0);	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r =0;
	int sum = 0;
	ll res = 0;
	while (r<n) {

		if ((sum ^ a[r] )== sum + a[r]) {
			sum ^= a[r];
			r++;
			res += f(l, r);


		}
		else {
			sum ^= a[l];
			l++;
			
		}
	}
	cout << res << "\n";
	return 0;
}