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
const int N = 305;
int n;
int a[N];
double dp[N][N][N];
bool vis[N][N][N];

double ddiv(double a , double b) {
  return a / b;
}

double f(int three , int two , int one) {
  int zero = n - three - two - one;
  if (zero == n) return 0;
  double &sol = dp[three][two][one];
  if (vis[three][two][one]) return sol;
  sol = 1, vis[three][two][one] = 1;
  if (three) {
    sol += f(three - 1 , two + 1 , one) * ddiv(three , n);
  }
  if (two) {
    sol += f(three , two - 1 , one + 1) * ddiv(two , n);
  }
  if (one) {
    sol += f(three , two , one - 1) * ddiv(one , n);
  }
  sol *= ddiv(n , n - zero);
  return sol;
}

int main() {
  scanf("%d" , &n);
  int one = 0, two = 0, three = 0;
  for (int i = 0, x ; i < n ; i++) {
    scanf("%d" , &x);
    if (x == 1) one++;
    if (x == 2) two++;
    if (x == 3) three++;
  }
  printf("%.10lf\n" , f(three , two , one));
  return 0;
}
