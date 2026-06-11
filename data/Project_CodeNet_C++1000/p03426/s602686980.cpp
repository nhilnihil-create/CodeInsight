#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int H, W, D;
pair<int, int> pr[90005];
ll d[900005];

int main(void) {
    scanf("%d %d %d", &H, &W, &D);
    for (int i=1; i<=H; i++) for (int j=1; j<=W;j++) {
      int a;
      scanf("%d", &a);
      pr[a] = mp(i, j);
    }
    
    for(int i=1; i<=H*W; i++) {
      if (i<=D) d[i] = 0;
      else {
        d[i] += abs(pr[i].first - pr[i-D].first) + abs(pr[i].second - pr[i-D].second) + d[i-D];
      }
    }
    
    int Q, ans = 0;
    scanf("%d", &Q);
    rep(i, 0, Q){
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", d[r] - d[l]);
    }

	return 0;
}
