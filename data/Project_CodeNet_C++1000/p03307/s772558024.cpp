#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long ll;

using namespace std;

int main()
{
	FastIO;
	ll n; 

	cin >> n;

	if(n % 2 == 0)
		cout << n << "\n";
	else 
		cout << 2*n << "\n";
	
	return 0;
}