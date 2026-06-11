#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int n, k;
  cin >> n >> k;
  deque<int> deq;
  rep(i,n) {
    int v;
    cin >> v;
    deq.push_back(v);
  }
  int ans = 0;
  for(int i = 0; i<=k; i++) {
    for(int j = 0; j<=k-i; j++) {
      deque<int> d = deq;
      vi have;
      rep(m,i) {
        if(!d.empty()) {
          have.push_back(d.front());
          d.pop_front();
        }
      }
      rep(l,j) {
        if(!d.empty()) {
          have.push_back(d.back());
          d.pop_back();
        }
      }
      sort(have.begin(),have.end());
      int tmp = 0;
      rep(m,have.size()) tmp += have[m];
      rep(m,k-i-j) {
        if(m<have.size() && have[m]<0) tmp -= have[m];
      }
      ans = max(ans,tmp);
    }
  }
  cout << ans << endl;
  return 0;
}