#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,k; cin >> n >> k;
  vb res(k+1,0);
  vi opts(n); for(int& i: opts) cin >> i;
  rep(i,0,k){
    if(!res[i]){
      for(auto j: opts)
        if(i+j <= k) res[i+j] = 1;
    }
  }
  if(res[k]) cout << "First";
  else cout << "Second";
}
