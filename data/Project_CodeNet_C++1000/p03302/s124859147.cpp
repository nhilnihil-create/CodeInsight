#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int a,b;
	cin >> a >> b;

	if(a+b == 15)
		cout << "+" << endl;
	else if(a*b == 15)
		cout << "*" << endl;
	else
		cout << "x" << endl;

	return 0;
}