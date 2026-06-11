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

int n;
int c[200005];
int main(void) {
  cin >> n;
  rep(i,0,n) {
    int p;
    scanf("%d", &p);
    c[p] = c[p-1]+1;
  }
  int mx = -1;
  rep(i,1,n+1) mx = max(mx, c[i]);

  
  cout << n-mx << endl;
  
  
    return 0;
}

