#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  string s;
  cin >> s;
  int ans=0;
  rep(i,3){
    if(s[i]=='a'){ans++; break;}
  }
  rep(i,3){
    if(s[i]=='b'){ans++; break;}
  }
  rep(i,3){
    if(s[i]=='c'){ans++; break;}
  }

  if(ans==3){cout << "Yes" << endl;}else{cout << "No" << endl;}
}