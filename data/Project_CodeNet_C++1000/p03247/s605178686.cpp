#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

const int maxn = 1100;
ll X[maxn]; ll Y[maxn]; int N;
ll ABS(ll x) { return (x >= 0) ? x : -x; }
ll d[50];

void solve(int k,int pos)
{
	ll XX = X[k]; ll YY = Y[k];
	ll x = 0; ll y = 0;
	for (int i = pos - 1; i >= 0; i--)
	{
		if (ABS(XX - x) > ABS(YY - y))
		{
			if (XX > x) { cout << 'R'; x += d[i]; }
			else if (XX < x) { cout << 'L'; x -= d[i]; }
		}
		else if(ABS(XX-x)<ABS(YY-y))
		{
			if (YY > y) { cout << 'U'; y += d[i]; }
			else if (YY < y) { cout << 'D'; y -= d[i]; }
		}
		else
		{
			if (XX >= x) { cout << 'R'; x += d[i]; }
			else if (XX < x) { cout << 'L'; x -= d[i]; }
		}
	}
	cout << endl;
}

int main()
{
	cin >> N;
	int flag0 = 0; int flag1 = 0; ll pmax = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> X[i] >> Y[i];
		if ((X[i] + Y[i]) % 2 == 0)flag0 = 1;
		else flag1 = 1;
		pmax = max(pmax, ABS(X[i]) + ABS(Y[i]));
	}
	if (flag0 == 1 && flag1 == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	ll sum = 0; int pos = 0;
	if (flag0 == 1) { d[pos++] = 1; sum += 1; }
	for (ll k = 0; k < 50; k++)
	{
		sum += (1 << k);
		d[pos++] = (1 << k);
		if (sum >= pmax)break;
	}
	cout << pos << endl;
	for (int i = pos - 1; i >= 0; i--)
		cout << d[i] << ' ';
	cout << endl;
	
	for (int i = 1; i <= N; i++)
		solve(i, pos);
	return 0;
}