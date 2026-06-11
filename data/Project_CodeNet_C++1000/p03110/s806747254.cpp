#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout<<fixed<<setprecision(10);
  double ans=0;
  rep(i,n){
    double mass ;
    string coin ;
    cin >> mass >> coin;
    if(coin =="JPY") ans += mass;
    if(coin == "BTC") ans += mass*380000.0;
  }
  cout << ans << endl;
}
