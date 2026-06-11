#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,m;
	cin >> n >> m;
	cout << ((n-m) *100 + 1900*m )* (1LL<<m) << endl;

}
