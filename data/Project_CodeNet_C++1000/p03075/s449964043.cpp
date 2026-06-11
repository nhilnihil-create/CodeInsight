#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  vi x(5);
  int k;
  rep(i, 5)cin >> x[i];
  cin >> k;

  string ans="Yay!";
  rep(i, 4){
    rep(j, 4-i){
      if(x[j+i+1]-x[i]>k){
        ans=":(";
        break;
      }
    }
    if(ans==":(")break;
  }

  cout << ans << endl;

  return 0;
}