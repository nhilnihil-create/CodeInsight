#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  vector<pair<long long, long long>> a(n);
  for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++){
    if(a[i].second <= m){
      ans += a[i].first * a[i].second;
      m -= a[i].second;
    }else{
      ans += m * a[i].first;
      break;
    }
  }
  cout << ans << endl;
}