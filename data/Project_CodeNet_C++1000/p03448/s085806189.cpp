#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

bool func(int n, int a, int b){
  int now = 0;
  while(n){
    now += n%10;
    n /= 10;
  }
  if(a <= now && now <= b) return true;
  return false;
}

int main(){
  int a,b,c,x; cin >> a >> b >> c >> x;
  int ans = 0;
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      for(int k = 0; k <= c; k++){
        int now = 500 * i + 100 * j + 50 * k;
        if(x == now) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
