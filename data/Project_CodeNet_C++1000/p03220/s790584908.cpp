#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  rep(i,n){
    cin >> h[i];
  }
  int key = 0;
  int res = 0;
  int ans = 100100100;
  vector<P> p(n);
  rep(i,n) {
    res = 1000*t-h[i]*6;
    p[i].second = abs(res-1000*a);
    p[i].first = i;
    if(ans >= p[i].second) {
      ans = p[i].second;
      key = p[i].first;
    }
  }
  cout << key+1 << endl;
}