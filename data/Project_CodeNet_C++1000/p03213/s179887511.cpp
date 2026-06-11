#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
  int n; cin >> n;
  vector<pair<int, int>> v;
  for(int i = 2; i <= n; i++){
    bool sosu = true;
    for(int j = 0; j < v.size(); j++){
      int x = v[j].first, y = i;
      while(y % x == 0){
        sosu = false;
        v[j].second++;
        y /= x;
      }
    }
    if(sosu) v.push_back(make_pair(i, 2));
  }

  int over5 = 0, over3 = 0, over15 = 0, over25 = 0, over75 = 0;
  rep(i, v.size()){
    if(v[i].second >= 75) over75++;
    if(v[i].second >= 25) over25++;
    if(v[i].second >= 15) over15++;
    if(v[i].second >= 5) over5++;
    if(v[i].second >= 3) over3++;
  }
  int ans = over75;
  ans += over25 * (over3 - 1);
  ans += over15 * (over5 - 1);
  ans += (over5 * (over5 - 1)) / 2 * (over3 - 2);
  cout << ans << endl;

  /*rep(i, v.size()){
    cout << v[i].first << " " << v[i].second << endl;
  }*/
  return 0;
}
