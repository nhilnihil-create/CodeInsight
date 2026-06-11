#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll q=0, j;
	for(auto &x : a)
		cin >> x;
	for(ll i=1; i<n; i++){
		if(i == 1)
			q = __gcd(a[i], a[i-1]);
		else
			q = __gcd(q, a[i]);
	}
	cout << q;
	return 0;
}