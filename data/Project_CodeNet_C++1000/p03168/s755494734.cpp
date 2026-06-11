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
const int N = 3005;
int n;
double pHead[N], dp[N][N];
bool vis[N][N];

double f(int cur , int head) {
  int tail = cur - head;
  if (cur >= n) return head > tail;
  double &sol = dp[cur][head];
  if (vis[cur][head]) return sol;
  vis[cur][head] = 1;
  return sol = f(cur + 1 , head + 1) * pHead[cur] + f(cur + 1 , head) * (1 - pHead[cur]);
}

int main() {
  scanf("%d" , &n);
  for (int i = 0 ; i < n ; i++) {
    scanf("%lf" , &pHead[i]);
  }
  printf("%.10lf\n" , f(1 , 1) * pHead[0] + f(1 , 0) * (1 - pHead[0]));
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
