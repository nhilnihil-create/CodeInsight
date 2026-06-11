#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
 
const long long INF = 1e15;
const int mod = 998244353;//1000000007;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int s[10005];

long long f(long long n)
{
	if(n < 0)
	{
		return 0; 
	}
	if(n % 4 == 0)
	{
		return n;
	}
	else if(n % 4 == 2)
	{
		return n + 1;
	}
	else if(n % 4 == 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	long long a, b;
	cin >> a >> b;
	long long temp = f(a - 1) ^ f(b);
	cout << temp;
}