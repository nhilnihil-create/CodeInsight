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
  int n = s.length();
  int l = 0, r = n - 1;
  int ans = 0;

  while (l < r) {
    if(s[l] == s[r]) {
      l++;
      r--;

    } else if (s[l] == 'x') {
      ans++;
      l++;
    } else if (s[r] == 'x') {
      ans++;
      r--;
    } else {
      puts("-1");
      return 0;
    }
  }

  cout << ans << endl;
}