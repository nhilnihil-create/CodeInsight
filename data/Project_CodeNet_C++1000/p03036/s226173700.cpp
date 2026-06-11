#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  ll r,d,x; cin >> r >> d >> x;
  for(int i = 0; i < 10; i++){
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}
