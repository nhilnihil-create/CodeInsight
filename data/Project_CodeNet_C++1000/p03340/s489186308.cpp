#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
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


int N;
ll A[200005], ans;

int main(void) {
  cin >> N;
  rep(i,0,N) scanf("%lld", &A[i]);
  int s = 0, t = 0;
  ll S = 0, X = 0;
  while(s<N) {
    while(t<N&&((S+A[t])==(X^A[t]))) {
      S += A[t];
      X ^= A[t];
      t++;
    }
    ans += t-s;
    S -= A[s];
    X ^= A[s];
    s++;
  }
  
  printf("%lld\n", ans);
  
	return 0;
}
