#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

#define pr_arr(name, a, b) \
  for (int i = (a); i < (b); i++) { \
    for (int j = (a); j < (b); j++) {\
      if (j > (a)) printf(" "); \
      printf("%lld", name[i][j]); \
    }\
    printf("\n");\
  }\

#define YES puts("YES")
#define NO  puts("NO")
#define Yes puts("Yes")
#define No  puts("No")

using namespace std;

typedef long long ll;

struct X { int p, n; };
//            1  2  3  4  5  6  7  8  9
int m[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> A;
X dp[10005];
int N, M;


//  1  2  3   4   5   6    7   8   9   10   11   
//  0  0  7   4   7   77  77  77 777  777  777

int main(void) {
    scanf("%d %d", &N, &M);
    rep(i, 0, M) {int a; scanf("%d", &a); A.pb(a);}
    sort(A.bg, A.en);

    rep(i, 0, A.size()) {
      dp[m[A[i]]].p = 1; dp[m[A[i]]].n = A[i];
    }

    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < A.size(); j++) {
        if (i-m[A[j]]<0 || dp[i-m[A[j]]].p==0) continue;
        int pos = dp[i-m[A[j]]].p + 1;
        if (pos >= dp[i].p) {
          dp[i].p = pos; dp[i].n = A[j];
        }
      }
    }

    string s;

    int i = N;
    while(dp[i].p > 0) {
      s += (dp[i].n + '0');
      i -= m[dp[i].n];
    }

  
    printf("%s\n", s.c_str());

	return 0;
}
