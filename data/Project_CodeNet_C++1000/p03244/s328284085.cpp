#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;
 
int main() {
  int n;
  cin >> n;
  map<int,int> a, b;
  rep(i,n/2) {
    int x, y;
    cin >> x >> y;
    a[x]++; b[y]++;
  }
  int maxa=0, maxb=0;
  int maxa2=0, maxb2=0;
  int A, B;
  for(auto p: a) {
    if(maxa<p.second) {
      maxa=p.second;
      A=p.first;
    }
  }
  for(auto p: a) {
    if(p.first==A) continue;
    maxa2=max(maxa2,p.second);
  }
  for(auto p: b) {
    if(maxb<p.second) {
      maxb=p.second;
      B=p.first;
    }
  }
  for(auto p: b) {
    if(p.first==B) continue;
    maxb2=max(maxb2,p.second);
  }
 
  int ans=n-maxa-maxb;
  if(A==B) ans=min(n-maxa-maxb2,n-maxa2-maxb);
  cout << ans << endl;
}