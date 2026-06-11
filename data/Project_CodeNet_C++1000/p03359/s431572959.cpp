#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int a,b;
  cin >> a >>b;
  int ans=0;
  for(int i=1;i<13;i++){
    if(i<a){ans++;}else if(i<=a && i<=b){ans++;}
  }
  cout << ans << endl;
}