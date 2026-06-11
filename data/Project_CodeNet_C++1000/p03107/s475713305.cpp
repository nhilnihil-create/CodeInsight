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
  int n=s.size();
  int zero=0,one=0;
  rep(i,n){
    if(s[i]=='0'){zero++;}else if(s[i]=='1'){one++;}
  }
  cout << 2*min(zero,one) << endl;
}