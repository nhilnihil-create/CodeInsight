#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  string t = "";
  rep(i, s.length()) {
    if(s[i] == 'x') continue;
    t.push_back(s[i]);
  }
  string rt = t;
  reverse(rt.begin(), rt.end());
  if(t != rt) {
    puts("-1");
    return 0;
  }
  int l = 0, r = s.length() - 1;
  int ans = 0;
  while(l < r) {
    if((s[l] != 'x' && s[r] != 'x') || (s[l] == 'x' && s[r] == 'x')) {
      ++l; --r;
      continue;
    }
    while(s[l] == 'x' && l < r) {
      ans++;
      l++;
    }
    while (s[r] == 'x' && l < r) {
      ans++;
      r--;
    }
  }
  cout << ans << endl;
}