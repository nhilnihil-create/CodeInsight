#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  string a; cin >> a;
  rep(s,1<<3){ //000 ~ 111
    string siki = "";
    siki += a[0];
    int ans = a[0]-'0';
    rep(i,3){
      if(s>>i&1) {
        ans += a[i+1]-'0';
        siki += "+";
        siki += a[i+1];
      }else{
        ans -= a[i+1]-'0';
        siki += "-";
        siki += a[i+1];
      }
    }
    siki += "=7";
    if(ans == 7){
      cout << siki << endl;
      return 0;
    }
  }
  return 0;
}