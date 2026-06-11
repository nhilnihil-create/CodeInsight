#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 0;
  int ans = 0;
  vector<int> d(200);
  for(int i = 1; i < min(a,b)+1; ++i) {
    if (a%i ==0 && b%i ==0) d.push_back(i);
  }
  std::sort(d.begin(),d.end(),std::greater<int>());
  ans = d[k-1];
  cout << ans << endl;
}
