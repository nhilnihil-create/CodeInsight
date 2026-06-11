#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 0;
  cin >> n;
  vector<P>a(n),b(n);
  rep(i,0,n) cin >> a[i].first >> a[i].second;
  rep(i,0,n) cin >> b[i].first >> b[i].second;
  sort(b.begin(),b.end());
  vector<bool>used(n,false);
  rep(i,0,n){
    int x = b[i].first,y = b[i].second,my = -1,py;
    rep(j,0,n){
      if(a[j].first < x && a[j].second > my && a[j].second < y && !used[j]){
        my = a[j].second;
        py = j;
      }
    }
    if(my != -1){
      ans++;
      used[py] = true;
    }
  }
  cout << ans << endl;
}