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
const int INF = 1001001001;
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> sum(n + 1);
  int sumw = 0;
  int sumb = 0;
  rep(i, n) {
    if(s[i] == '#') sumb++;
    else sumw++;
  }

  int ans = min(sumw, sumb);
  int black = 0;
  int white = 0;
  rep(i, n) {
    if (s[i] == '#') black++;
    else white++;
    int value = black + (n - sumb - white);
    ans = min(ans, value);
  }
  cout << ans << endl;
  
}