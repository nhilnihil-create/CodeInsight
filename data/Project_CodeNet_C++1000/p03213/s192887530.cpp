#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 123;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int a[105];
int Prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int Count(int x)
{
	int cnt = 0;
	for(int i = 0; i <= 14; i++)
	{
		if(a[i] >= x - 1)
		{
			cnt++;
		}
	}
	return cnt;
}

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 0; i <= 14; i++)
	{
		int temp = n;
		while(temp > 0)
		{
			a[i] += temp / Prime[i];
			temp /= Prime[i];
		}
	}
	cout << Count(75) + Count(25) * (Count(3) - 1) + Count(15) * (Count(5) - 1) + Count(5) * (Count(5) - 1) * (Count(3) - 2) / 2;
}