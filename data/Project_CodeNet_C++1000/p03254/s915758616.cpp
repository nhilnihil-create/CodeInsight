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
using ii = pair <int , int>;
void in(int &x);
// const int N = ;
#define singleCase
// #define multipleCase
int n,x;

void work() {
   in(n); in(x);
   vector <int> v(n);
   for (int i = 0 ; i < n ; i++) {
      in(v[i]);
   }
   sort(all(v));
   int sol = 0, lst = -1;
   for (int i = 0 ; i < n ; i++) {
      if (x >= v[i]) {
         sol++, lst = i, x -= v[i];
      }
   }
   if (lst == n - 1 && x > 0) sol--;
   printf("%d\n" , sol);
   return;
}

int main() {
   #ifdef multipleCase
      int nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(int &x) {
	bool neg = false;
	register int c;
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
