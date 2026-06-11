#include <bits/stdc++.h>
#define x first
#define y second
#define maxn 1000000
using namespace std;
map <int, long long int> mp;  // h[i] dp[i]
long long int h[maxn],a[maxn];
int main()
{
	int N; cin >> N;
	mp[0]=0; 

	for(int i = 0; i < N; i++)
		cin >> h[i];

	for(int i = 0; i < N; i++)
		cin >> a[i];

	//mp[h[0]] = a[0];

	for(int i = 0; i < N; i++)
	{
		auto p = mp.upper_bound(h[i]);
		auto ps = prev(p);
		long long int tmp = a[i] + ps -> y;

		while(mp.end() != p && p->y <= tmp)
			mp.erase(p++);
		mp[h[i]] = tmp;
	}

	cout << prev(mp.end())->y <<endl;
}