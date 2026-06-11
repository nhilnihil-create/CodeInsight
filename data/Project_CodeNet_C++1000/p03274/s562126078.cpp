#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> mx, x;
  for(int i=0; i<n; i++){
    ll a;
    cin >> a;
    if(a<0) mx.push_back(abs(a));
    else x.push_back(a);
  }
  sort(mx.begin(), mx.end());
  sort(x.begin(), x.end());
  ll ans = 1000000000009;
  for(int i=0; i<=mx.size(); i++){
    if(i==0){
      if(k>x.size()) continue;
      ans = min(x[k-1], ans);
      continue;
    }
    if(k-i>x.size()) continue;
    if(k<i) continue;
    ll tmp;
    if(k==i) tmp = mx[k-1];
    else tmp = min(mx[i-1], x[k-i-1]) + mx[i-1] + x[k-i-1];
    ans = min(tmp, ans);
  }
  for(int i=0; i<=x.size(); i++){
    if(i==0){
      if(k>mx.size()) continue;
      ans = min(mx[k-1], ans);
      continue;
    }
    if(k-i>mx.size()) continue;
    if(k<i) continue;
    ll tmp;
    if(k==i) tmp = x[k-1];
    else tmp = min(x[i-1], mx[k-i-1]) + x[i-1] + mx[k-i-1];
    ans = min(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}
