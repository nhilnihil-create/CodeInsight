#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int,int> ii;

int l;
int w[61];
vector<ii> E;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> l;
	for (int i=2;i<=20;i++)
		E.push_back(ii(i-1,i));
	l--;
	int MSB;
	for (int i=19;i>=0;i--)
		if ((l >> i) & 1)
		{
			MSB = i;
			break;
		}
	for (int i=0;i<MSB;i++)
		{
			w[E.size()] = (1<<i);
			E.push_back(ii(20-i-1,20-i));
		}
	int cur = (1 << MSB);	
	for (int i=MSB-1;i>=0;i--)
		if ((l >> i) & 1)
		{
			w[E.size()] = cur;
			E.push_back(ii(1,20-i));
			cur |= (1 << i);
		}
	w[E.size()] = cur;
	E.push_back(ii(1,20));
	cout << 20 << ' ' << E.size() << '\n';
	for (int i=0;i<E.size();i++)
		cout << E[i].first << ' ' << E[i].second << ' ' << w[i] << '\n';
}