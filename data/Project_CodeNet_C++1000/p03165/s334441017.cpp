#include<bits/stdc++.h>

using namespace std;


#define ff				first
#define ss				second
#define int				long long
#define pb				push_back
#define mp				make_pair
#define pii				pair<int,int>
#define vi				vector<int>
#define mii 			map<int,int>
#define	pqb				priority_queue<int>
#define pqs				priority_queue<int,vi,greater<int> >
#define setbits(x)		__builtin_popcountll(x)
#define zrobits(x)		__builtin_ctzll(x)
#define mod				1000000009
#define inf 			1e18
#define ps(x,y)			fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr = new type[n]
#define w(x)			int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl			'\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int maxn = 1e5 + 5;
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}


bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	}
	return true;
}

set<int> Sieve(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}
	set<int> primes;

	for (int i = 2; i <= n; i++)
	{
		if (prime[i])
			primes.insert(i);
	}
	return primes;
}
set<int> primeFactors(int  n)
{
	set<int> factors;
	while (n % 2 == 0)
	{
		n /= 2;
		factors.insert(2);

	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		// int count = 0;
		while (n % i == 0)
		{
			factors.insert(i);
			n /= i;
		}
	}
	if (n > 2)
		factors.insert(n);
	return factors;
}

int power(int x, unsigned int y, int p)
{
	int res = 1;

	x = x % p;

	if (x == 0) return 0;
	;
	while (y > 0)
	{

		if (y & 1)
			res = (res * x) % p;

		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;

}

void lcs(string text1, string text2)
{
	int n = text1.length();
	int m = text2.length();

	int cache[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				cache[i][j] = 0;
			}
			else if (text1[i - 1] == text2[j - 1])
			{
				cache[i][j] = 1 + cache[i - 1][j - 1];
			}
			else
			{
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}
	int index = cache[n][m];
	char ans[index + 1];
	ans[index] = '\0';
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (text1[i - 1] == text2[j - 1])
		{
			ans[index - 1] = text1[i - 1];
			i--;
			j--;
			index--;
		}
		else if (cache[i - 1][j] > cache[i][j - 1])
		{
			i--;
		}
		else
			j--;
	}
	cout << ans << endl;

}


// Graph------------------------------------------------------------------------


int32_t main()
{
	FIO;
	// c_p_c();
	// --------------------------------------------------
	// Never GIVE UP !!!!
	string s1, s2;
	cin >> s1;
	cin >> s2;

	lcs(s1, s2);

}