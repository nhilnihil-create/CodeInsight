#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
bitset<maxn * maxn / 2> r;
int a[maxn];
int s = 0; 
int main() {
	int n;
	cin >> n;
	r[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		r = (r | (r << a[i]));
		s += a[i];
	}
	if (s & 1) s++;
	s /= 2;
	while (!r[s]) s++;
	cout << s << endl;
	return 0;
}
