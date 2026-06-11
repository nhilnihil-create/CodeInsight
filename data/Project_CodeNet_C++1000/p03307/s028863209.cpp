#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
string yes = "Yes\n";
string no = "No\n";

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return (gcd(b, a % b));
}

int  lcm(int a, int b)
{
	return (a * b / gcd(a,b));
}

int  main()
{
	int n; cin >> n;
	cout << lcm(n,2) << endl;
	return 0;
}
