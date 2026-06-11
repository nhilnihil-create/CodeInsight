#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  int x=0;
  int ans=0;
  while(true){
    while(h.at(x)==0){
      x++;
      if(x==n){
        cout << ans << endl;
        return 0;
      }
    }
    for(int i=x;i<n;i++){
      if(h.at(i)==0){
        ans++;
        break;
      }
      else if(i==n-1){
      h.at(i)--;
        ans++;
      }
      else
        h.at(i)--;
    }
  }
}