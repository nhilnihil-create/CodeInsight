#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int h,w,n;
  cin >> h >> w >> n;
  int Sy,Sx;
  cin >> Sy >> Sx;
  string s,t;
  cin >> s >> t;
  ll L = Sx,R = Sx,U = Sy,D = Sy;
  bool is = false;
  rep(i,n){
    if(s[i] == 'L'){
      L--;
      if(L <= 0)is = true;
    }else if(s[i] == 'R'){
      R++;
      if(R > w)is = true;
    }else if(s[i] == 'U'){
      U--;
      if(U <= 0)is = true;
    }else if(s[i] == 'D'){
      D++;
      if(D > h)is = true;
    }
    if(t[i] == 'L')R = max(1ll,R-1);
    else if(t[i] == 'R')L = min(w*1ll,L+1);
    else if(t[i] == 'U')D = max(1ll,D-1);
    else if(t[i] == 'D')U = min(h*1ll,U+1);
  }
  cout << (is ? "NO" : "YES") << endl;


  




  return 0;
}