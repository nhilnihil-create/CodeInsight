#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	using ll = long long;
	ll n;
	cin >> n;
	if(n%2 == 0) {
		cout << n;
	} else {
		cout << 2*n;
	}
}
