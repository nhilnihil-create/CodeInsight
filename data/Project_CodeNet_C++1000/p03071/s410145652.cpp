#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ll long long
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int binaryExponentiation(int base, int power, int modular)
{
	int res = 1;
	while (power)
	{
		if (power % 2 == 0)
		{
			power /= 2;
			base = (base * base) % modular;
		}
		else
		{
			res = (res * base) % modular;
			power--;
		}
	}
	return res;
}

bool prime[1000001];
int pp[1000001];
void sieve()
{
	memset(prime, true, sizeof(prime));
	int i, j;
	prime[1] = false;
	prime[0] = false;
	for (i = 2; i * i <= 1000000; i++)
	{
		if (prime[i])
		{
			for (j = i * i; j <= 1000000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	int count = 0;
	for (i = 1; i <= 1000000; i++) {
		if (prime[i]) {
			count++;
		}
		if (prime[count])
			pp[i] = 1;
		else
			pp[i] = 0;
	}


}
int FindLCM(int a, int b)
{
	return (a * b) / __gcd(a, b);
}
int rangeDivisor(int m, int n, int a, int b)
{

	int lcm = FindLCM(a, b);

	int a_divisor = n / a - (m - 1) / a;
	int b_divisor = n / b - (m - 1) / b;

	// Find common divisor by using LCM
	int common_divisor = n / lcm - (m - 1) / lcm;

	int ans = a_divisor + b_divisor - common_divisor;
	return ans;
}
int32_t main()
{
		int a, b;
	cin >> a >> b;
	cout << max((a + b), max(a + a - 1, b + b - 1));
}
