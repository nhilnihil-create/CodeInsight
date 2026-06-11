#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  int l = 0, r = 0;
  rep(i, 2){
    l *= 10; r *= 10;
    l += s.at(i)-'0'; r += s.at(i+2)-'0';
  }
  bool f1 = (r != 0 && r <= 12), f2 = (l != 0 && l <= 12);
  if(f1 == true && f2 == true) cout << "AMBIGUOUS" << endl;
  else if(f1 == true) cout << "YYMM" << endl;
  else if(f2 == true) cout << "MMYY" << endl;
  else cout << "NA" << endl;
  return 0;
}