#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  int t=0, x=0, y=0;
  rep(i,N){
    int ta, xa, ya; cin >> ta >> xa >> ya;
    if( (ta-t)%2 == (abs(xa-x)+abs(ya-y))%2 && abs(xa-x)+abs(ya-y) <= ta-t ){
      x = xa;
      y = ya;
      t = ta;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
   
   cout << "Yes" << endl;
   return 0;
}