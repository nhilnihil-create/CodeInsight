#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 2018, rt = 1<<10;
ll s(ll n) {
	if(n < 10) return n;
	return n%10 + s(n/10);
}
double f(ll x) {
	return (double)x/s(x);
}
ll cur = 1, d = 1;
bool good(ll i) {
	int ok = 1;
	for(ll q = 1; q <= 1000000000000000; q *= 10) {
		ok &= f(i) <= f(i+q);
	}
	return ok;
}
void next() {
	if(!good(cur+d)) d *= 10;
	cur += d;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int k;
	cin >> k;
	while(k--) {
		cout << cur << '\n';
		next();
	}
}
