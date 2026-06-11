#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int x; cin >> x;
  vector<bool> chk(x+1);
  chk[1] = 1;
  for(int i = 2; i <= x; i++){
    int now = i*i;
    while(now <= x){
      chk[now] = true;
      now *= i;
    }
  }
  for(int i = x; i >= 1; i--){
    if(chk[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
