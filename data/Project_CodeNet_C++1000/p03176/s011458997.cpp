#include <bits/stdc++.h>
#define MAXN 200005
#define ll long long

using namespace std;

int n;
ll h[MAXN], a[MAXN], arvore[MAXN];





ll soma(ll x)
{
	ll sum = 0;
	for (ll i = x; i > 0; i -= (i & -i))
	{
		sum = max(arvore[i], sum);
	}

	return sum;
}


void update(ll x, ll sum)
{
	for (ll i = x; i < MAXN; i += (i & -i))
	{
		arvore[i] = max(arvore[i], sum);
	}	


}



int main()
{
	
	cin >> n;

	memset(arvore, 0, sizeof(arvore));

	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
	{
		ll x = soma(h[i]);
		update(h[i], a[i] + x);
	}


	cout << soma(n) << endl;















	return 0;
}