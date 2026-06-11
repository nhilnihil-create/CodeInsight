#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,h,ans = 0;
  cin >> n >> h;
  vector<P>data;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    data.push_back(P(a,0));
    data.push_back(P(b,1));
  }
  sort(data.begin(),data.end());
  reverse(data.begin(),data.end());
  rep(i,2*n){
    if(data[i].second == 0){
      ans += h/data[i].first;
      if(h%data[i].first != 0) ans++;
      cout << ans << endl;
      return 0;
    }
    else{
      ans++;
      h -= data[i].first;
      if(h <= 0){
        cout << ans << endl;
        return 0;
      }
    }
  }
}