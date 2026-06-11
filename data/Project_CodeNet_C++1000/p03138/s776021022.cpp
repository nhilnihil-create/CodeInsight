#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>


#define rep(i, a, b) for ( ll i = (a); i < (b); i++ )
#define per(i, a, b) for ( ll i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()
#define DEBUG_INT(var) printf("the value of "#var" is %lld\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) rep(i, begin, end) PRINT_ARRAY(name, i)


using namespace std;

typedef long long ll;


ll N, K;
ll A[100005];
ll dp[50][2];

int main(void) {
    scanf("%lld %lld", &N, &K);
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
    
    dp[45][0] = 0;
    bool smaller = false;
    for (int i=45; i>=0; i--) {
      ll num = 0;
      for(ll j=0; j<N; j++) if ((A[j]>>i)&1)  num++;
      
      for (int j=1; j>=0; j--) {
        if (j && !smaller) continue;
        int u = j ? 1 : ((K>>i)&1);
        for (int k=0; k<=u; k++) {
          dp[i][(j || k < u)] = max(dp[i][(j || k < u)], dp[i+1][j] + (1LL<<i)*(k?(N-num) : num));
        }
        if (u) smaller = true;
      
      }
    
    }
    
    printf("%lld\n", max(dp[0][0], dp[0][1]));
    return 0;
}
