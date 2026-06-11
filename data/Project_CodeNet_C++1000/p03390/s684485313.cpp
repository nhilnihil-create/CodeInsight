#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, ans;
int q;
int main()
{

	scanf("%d", &q);
	while(q--)
	{
		cin >> A >> B;
		if(A == 1 && B == 1)
		{
			puts("0");
			continue;
		}
		ll tot = A * B - 1;
		ll sqtot = sqrt(tot);
		while(sqtot * sqtot > tot) --sqtot;
		while((sqtot + 1) * (sqtot + 1) <= tot) ++sqtot;
		ll ans = 2 * sqtot - (sqtot == tot / sqtot);
		if(tot / A != tot / (A + 1) && (A == 1 || tot / A != tot / (A - 1))) --ans;
		if(tot / B != tot / (B + 1) && (B == 1 || tot / B != tot / (B - 1))) --ans;
		cout << ans << endl;
	}
	return 0;
}
		 
	