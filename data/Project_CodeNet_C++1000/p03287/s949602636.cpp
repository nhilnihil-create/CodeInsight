#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n , m , r;
ll ans;
map<int , int> rem;
int main()
{
	abdelrahman010
	cin >> n >> m;
	for(int i = 0 , x;i < n;i++)
	{
		cin >> x;
		r = (r + x) % m;
		ans += 1ll * rem[r] + !r;
		rem[r]++;
	}
	cout << ans;
	return 0;
}
