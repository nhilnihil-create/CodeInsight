#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll A,B;
	cin >> A >> B;
	B++;
	ll ans = 0;
	ll tempB = B / 2;
	ll tempA = A / 2;
	if ((tempB - tempA) % 2 == 1) ans += 1;
	for (int i = 2; i < 45; ++i)
	{
		tempB = B % (1ull << i);
		tempB = max(ll(0),tempB - ll(1ull << (i-1)));
		tempA = A % (1ull << i);
		tempA = max(ll(0),tempA - ll(1ull << (i-1)));
		//cout << tempA << " " << tempB << " " << i << endl;
		if ((tempB - tempA) % 2 != 0) 
		{
			ans += ll(1ull << (i-1));
			//cout << i-1 << endl;
		}
	}
	cout << ans << endl;
	return 0;
}