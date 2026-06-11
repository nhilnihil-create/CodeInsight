#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll n; cin >> n;
	ll a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << ll(5) + (n - 1) / (min({a, b, c, d, e})) << endl;
    return 0;
}
