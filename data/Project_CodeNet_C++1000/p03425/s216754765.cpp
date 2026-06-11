#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;

int main(){
  int n;
  cin >> n;
  ll ans = 0;
  vector<ll> march(5,0);
  string m = "MARCH";
  rep(i, n){
    string s;
    cin >> s;
    rep(j, 5){
      if(s.at(0)==m.at(j)) march.at(j)++;
    }
  }
  rep(i, 3){
    for(int j = i+1; j<4;j++){
      for(int k=j+1; k<5;k++){
        ans += march.at(i) * march.at(j) * march.at(k);
      }
    }
  }
  cout << ans;
}