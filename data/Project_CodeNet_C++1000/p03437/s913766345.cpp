
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i )
#define rep_rev(n,i) for(ll i = n; i >= 0; --i )
using namespace std;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
  int X,Y; cin >> X >> Y;
  if(X % Y == 0){
    cout << "-1" << endl;
    return 0;
  }
  else{
    int x = 2;
    while(1){
      if(X*x%Y!=0){
        cout << X*x << endl;
        return 0;
      }
      x++;
    }
  }
  return 0;
}