#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,m,x;
  cin >> n >> m >> x;
  set<int> s;
  rep(i,m){
    int k;
    cin >> k;
    s.insert(k);
  }
  int f = 0;
  int l = 0;
  rep(i,n){
    if(!s.count(i)) continue;
    if(i < x) f++;
    else l++;
  }
  int ans = min(f,l);
  cout << ans << endl;
}