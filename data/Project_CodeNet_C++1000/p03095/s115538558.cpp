/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin() , x.rend()
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
// const ll N = ;
const ll m = 1e9 + 7;
#define singleCase
// #define multipleCase
ll n,freq[500];
string s;

ll subs(ll a , ll b) {
   return (((a % m) - (b % m)) + m) % m;
}

void work() {
   cin >> n;
   cin >> s;
   for (ll i = 0 ; i < n ; i++) {
      freq[s[i]]++;
   }
   ll sol = 1;
   for (char i = 'a' ; i <= 'z' ; i++) {
      (sol *= (freq[i] + 1)) %= m;
   }
   sol = subs(sol , 1);
   printf("%lld\n" , sol);
   return;
}

int main() {
   #ifdef multipleCase
      ll nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(ll &x) {
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	  x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
