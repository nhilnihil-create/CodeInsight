#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n,m;
int main()
{
	cin >> n >> m;
	if(n == 1 && m == 1) cout << 1;
	else if(n == 1 && m > 1) cout << m-2;
	else if(n > 1 && m == 1) cout << n-2;
	else cout << 1LL*(n-2)*(m-2);
	//ans;
	return 0;
}
