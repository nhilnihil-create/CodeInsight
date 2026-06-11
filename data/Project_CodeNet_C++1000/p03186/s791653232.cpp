#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll a, b, c; cin >> a >> b >> c;
	if(c <= (a + b) ) {
		cout << b + c << endl;
	}else {
		cout << (a + b) + b + 1<< endl;
	}
}	