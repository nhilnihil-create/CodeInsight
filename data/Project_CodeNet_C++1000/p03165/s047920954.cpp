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
const int INF = 1e9;
const int N = 3005;
char s[N], t[N];
int sl, tl, dp[N][N];

int f(int curs , int curt) {
  if (curs > sl || curt > tl) return 0;
  int &sol = dp[curs][curt];
  if (sol != -1) return sol;
  sol = max(f(curs + 1 , curt) , f(curs , curt + 1));
  if (s[curs] == t[curt]) {
    sol = max(sol , f(curs + 1 , curt + 1) + 1);
  }
  return sol;
}

void backtrack(int curs , int curt) {
  if (curs > sl || curt > tl) return;
  int take = -INF, skips, skipt;
  skips = f(curs + 1 , curt);
  skipt = f(curs , curt + 1);
  if (s[curs] == t[curt]) {
    take = f(curs + 1 , curt + 1) + 1;
  }
  if (take >= max(skips , skipt)) {
    printf("%c" , s[curs]);
    backtrack(curs + 1 , curt + 1);
  } else {
    if (skips > skipt) {
      backtrack(curs + 1 , curt);
    } else {
      backtrack(curs , curt + 1);
    }
  }
}

int main() {
  scanf("%s" , s + 1);
  scanf("%s" , t + 1);
  sl = strlen(s + 1);
  tl = strlen(t + 1);
  memset (dp , -1 , sizeof dp);
  backtrack(1 , 1);
  puts("");
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
