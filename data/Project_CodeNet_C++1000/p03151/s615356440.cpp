#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  ll sum = 0;
  vi diff;
  rep(i,n){
    sum += a[i]-b[i];
    if(0 <= a[i]-b[i]) diff.push_back(a[i]-b[i]);
  }
  if(sum < 0){
    cout << -1;
    return 0;
  }
  sort(all(diff));
  int ans = n;
  rep(i,n){
    if(sum < 0 || sum < diff[i]) break;
    ans--;
    sum -= diff[i];
  }
  cout << ans;
  cout << "\n";
  return 0;
}
