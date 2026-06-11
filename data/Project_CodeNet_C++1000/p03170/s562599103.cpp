/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <int , int>;
void in(int &x);
const int N = 1e5 + 10;
int n, k;
int a[105];
bool dp[N], vis[N];

bool f(int left) {
  if (left == 0) return 1;
  bool &sol = dp[left];
  if (vis[left]) return sol;
  vis[left] = 1;
  bool nxt = 0;
  for (int i = 1 ; i <= n ; i++) {
    if (left >= a[i]) {
      nxt |= f(left - a[i]);
    }
  }
  sol = !nxt;
  return sol;
}

int main() {
  in(n); in(k);
  for (int i = 1 ; i <= n ; i++) {
    in(a[i]);
  }
  puts(f(k) ? "Second" : "First");
  return 0;
}

void in(int &x){
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if(c == '-'){
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
