#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define ff first
#define ss second
#define file_se_input  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pp long long int
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pb push_back
#define mp make_pair
#define pi 3.141592653589793238
#define eb emplace_back
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define zip(i,a,b) for(int i=a;i<b;i++)
#define rzip(i,a,b) for(int i=a;i>=b;i--)
#define ll unsigned long long int
#define test int t;cin>>t; while(t--)
#define um unordered_map
#define en '\n'
#define us unordered_set
typedef pair<int, int>     pii;
typedef pair<char, int>    pci;
typedef pair<char, char>   pcc;
typedef vector<pii>       vii;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define INF (1e18+5)
#define inf (1e9+5)
#define mod 1000000007


bool check_prime(long long n)
{
	int flag = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (n == 1)
		return false;
	else if (flag == 0 || n == 2 || n == 3)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int BE(int x, int n, int m) //function to calculate x raise to power n modulo m
{
	int result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = result * x % m;
		x = x * x % m;
		n = n / 2;
	}
	return result;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	if (fopen("input.txt", "r"))
	{
		freopen ("input.txt" , "r" , stdin);
		freopen ("output.txt" , "w" , stdout);
	}
#endif
	//_______________________________-code starts-_______________________________________________

	int n;
	cin >> n;
	int a[n];
	zip(i, 0, n)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << a[0] << en;
		return 0;
	}
	if (n == 2)
	{
		cout << max(a[0], a[1]) << en;
		return 0;
	}
	if (n == 3)
	{
		cout << max(__gcd(a[0], a[1]), max(__gcd(a[1], a[2]), __gcd(a[0], a[2]))) << en;
		return 0;
	}
	//we will store GCDs in l[i] ans r[i]  where l[i]=gcd upto ith terms
	// and r[i]=gcd from n-1 to i+2th terms

	int l[n + 1];
	//l[0] = 0;
	l[0] = a[0];

	for (int i = 1; i < n; i++)
	{
		l[i] = __gcd(l[i - 1], a[i]);
	}
	int r[n + 1] = {0};
	r[n - 1] = a[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		r[i] = __gcd(r[i + 1], a[i]);
	}
	int lar = 0;
	for (int i = 0; i < n - 2; i++)
	{
		lar = max(lar, __gcd(l[i], r[i + 2]));
	}
	int y = max(lar, max(r[1], l[n - 2]));
	cout << y << en;




	return 0;
}


