
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
#define all(v) (v).begin(), (v).end()
#define sz(v) (int) (v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

vector<int> ans, v;

int main(void) {
  int n;
  cin >> n;
  rep(i, 0, n) {
    int a;
    cin >> a;
    v.pb(a);
  }
  
  while(sz(v)>0) {
    int idx = -1;
    for (int i=sz(v)-1; i>=0; i--) {
      if (v[i]==i+1) {idx = i; break;}
    }
    if(idx==-1){puts("-1"); return 0;}
    ans.pb(v[idx]);
    v.erase(v.bg + idx);
  }
  
  for(int i=sz(ans)-1; i>=0; i--) printf("%d\n", ans[i]);
  
	return 0;
}
