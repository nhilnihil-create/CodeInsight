#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> vec(n+1);
  rep(i,n) cin >> vec.at(i);
  vec.at(n) = 1'000'000'001;
  sort(vec.begin(),vec.end());
  int cnt = 1;
  int ans = 0;
  rep(i,n){
    /*cout << cnt << endl;
    cout << ans << endl;
    cout << vec.at(i) << endl;
    cout << endl;*/
    if (vec.at(i) == vec.at(i+1)){
      cnt++;
      continue;
    }
    else if (vec.at(i) > cnt) ans += cnt;
    else if (vec.at(i) < cnt) ans += cnt - vec.at(i);
    cnt = 1;
  }
  cout << ans << endl;
  return 0;
}
