#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }


signed main()
{
	string S;
	cin >> S;
	bool valid = true;

	if (S[0] != 'A')
	{
		valid = false;
	}

	int c_cnt = 0;
	int c_pos = 0;
	for (int i = 2; i < S.length() - 1; i++)
	{
		if (S[i] == 'C')
		{
			c_cnt++;
			c_pos = i;
		}
	}
	if (c_cnt != 1)
	{
		valid = false;
	}

	for (int i = 1; i < S.length(); i++)
	{
		if (i == c_pos) continue;
		if (!islower(S[i]))
		{
			valid = false;
		}
	}

	cout << (valid ? "AC" : "WA") << endl;
}

//
//const int MOD = 998244353;
//int m_add(int a, int b)
//{
//	return (a + b) % MOD;
//}
//int m_sub(int a, int b)
//{
//	return (a + MOD - b) % MOD;
//}
//int m_mul(int a, int b)
//{
//	return (a * b) % MOD;
//}
//int m_pow(int x, int n)
//{
//	if (n == 0) return 1;
//	ll res = m_pow((x * x) % MOD, n / 2);
//	if (n & 1) res = (res * x) % MOD;
//	return res;
//}
//int m_divide(int a, int b)
//{
//	return m_mul(a, m_pow(b, MOD - 2));
//}
//int m_comb(int n, int r)
//{
//	int i;
//	int p = 1;
//	for (i = 1; i <= r; i++)
//	{
//		p = m_mul(p, (n - i + 1));
//		p = m_divide(p, i);
//	}
//	return p;
//}
//int m_comb_with_rep(int n, int r)
//{
//	return m_comb(n + r - 1, r);
//}
//
//
//
//signed main()
//{
//	int N, M, K;
//	cin >> N >> M >> K;
//
//
//	int ans = 0;
//
//	int xx = m_pow(M - 1, N - 1);
//	int yy = m_comb_with_rep(2, 0);
//	int zz = m_mul(xx, yy);
//	zz = m_mul(zz, M);
//	ans = m_add(ans, zz);
//
//	int x = 0;
//	int y = 0;
//	for (int k = 1; k <= K; k++)
//	{
//		int a = max(0LL, k + 1);
//		int b = max(0LL, N - (k * 3) + 1);
//		if (k <= 1)
//		{
//			x = m_pow(M - 1, N - 1);
//		}
//		else
//		{
//			x = m_sub(x, M - 1);
//		}
//
//		if (k <= 1)
//		{
//			y = m_comb_with_rep(a, b);
//		}
//		else
//		{
//			int q = ((N - 3 * k + 1) * k) % MOD;
//			int w = (N - 2 * k + 1) % MOD;
//			y = m_mul(y, q);
//			y = m_divide(y, w);
//		}
//
//		int z = m_mul(x, y);
//		z = m_mul(z, M);
//		ans = m_add(ans, z);
//	}
//
//	cout << ans << endl;
//}

