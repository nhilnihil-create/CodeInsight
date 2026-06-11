#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k,a = 0,b = 0;
  cin >> n >> k;
  vector<int> x;
  REP(i,n){
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
  int ans = 1000000000;
  REP(i,n-k+1){
    int r,l;
    r = abs(x.at(i))+abs(x.at(i+k-1)-x.at(i));
    l = abs(x.at(i+k-1))+abs(x.at(i)-x.at(i+k-1));
    ans = min({ans,r,l});
  }
  cout << ans << endl;
}
