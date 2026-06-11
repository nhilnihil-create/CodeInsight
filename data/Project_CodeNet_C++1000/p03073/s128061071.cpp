#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S; cin >> S;
  int ans1 = 0, ans2 = 0;
  rep(i,S.size()) {
    if (i%2==0 && S[i]=='0') ++ans1;
    if (i%2==0 && S[i]=='1') ++ans2;
    if (i%2==1 && S[i]=='1') ++ans1;
    if (i%2==1 && S[i]=='0') ++ans2;
  }
  cout << min(ans1, ans2) << endl;

  return 0;
}