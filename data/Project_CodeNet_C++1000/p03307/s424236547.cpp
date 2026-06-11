#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

template<typename T>
T in() { T x; cin >> x; return (x); }

template<typename T1,typename T2>
inline T1 gcd(T1 a, T2 b) { if (a%b == 0)return (b); return (gcd(b, a%b)); }

int lcm(int a, int b){	return a * b / gcd(a, b);}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
  	ll a = in<ll>();
	
  	cout << lcm(2,a) << endl;

	return 0;
}