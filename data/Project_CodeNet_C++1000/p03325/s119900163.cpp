#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >>n;
  int cnt = 0;
  rep(i,n){
    ll a;
    cin >>a;
    bool can = true;
    while(can){
      if(a%2==0){
        a/=2;
        cnt++;
      }
      else can = false;
    }
  }
  cout << cnt << endl;
  return 0;
}