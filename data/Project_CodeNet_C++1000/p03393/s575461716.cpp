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

	string s;
	cin >> s;
	int n = s.size();
	map<char, int>mt;
	zip(i, 0, n)
	{
		mt[s[i]] = i + 1;
	}
	int a, b, c;
	if (n == 26)
	{
		int flag = 0;
		//cout << s << en;
		zip(i, 1, n)
		{
			if (s[i] < s[i - 1])
			{
				if (i == n - 1 && flag == 0)
				{
					cout << -1 << en;
					return 0;
				}
			}
			else
			{
				// flag = 1;
				// a = i;
				// b = i - 1;
				break;
			}
		}
		flag = 25;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] < s[i - 1])
			{
				flag = i - 1;
			}
			else
			{
				//cout << s[i] << en;
				break;
			}
		}
		//cout << s << en;
		char ch = 'z';
		//cout << flag << en;
		if (flag == 1)
		{
			ch = s[0] + 1;
			cout << ch << en;
			return 0;
		}
		zip(i, 0, flag - 1)
		{
			cout << s[i];
		}
		int j = flag - 1;
		ch = 'z';
		zip(i, flag, n)
		{
			if (s[i] > s[j])
			{
				ch = min(ch, s[i]);
			}
		}
		cout << ch << en;


		// c = b - 1;
		// char ch = s[c];
		// char ans;
		// for (char x = ch + 1; x <= 'z'; x++)
		// {
		// 	if (mt[x] > b + 1)
		// 	{
		// 		ans = x;
		// 		break;
		// 	}
		// }
		// zip(i, 0, c + 1)
		// {
		// 	cout << s[i];
		// }
		// cout << ans;
		// cout << en;
		// //swap(s[a], s[b]);

		return 0;
	}
	char a1;
	for (char x = 'a'; x <= 'z'; x++)
	{
		if (mt[x] == 0)
		{
			a1 = x;
			break;
		}
	}
	cout << s << a1 << en;

	return 0;
}

