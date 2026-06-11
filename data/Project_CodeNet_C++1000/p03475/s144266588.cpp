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
  int n;
  cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i, n-1){
    cin >> c.at(i) >> s.at(i) >> f.at(i);
  }
  rep(i, n){
    int pos = i, time = 0;
    while(pos != n-1){
      if(time <= s.at(pos)){
        time = s.at(pos) + c.at(pos);
      }else{
        int m1 = (time+f.at(pos)-1) / f.at(pos);
        time = m1*f.at(pos) + c.at(pos);
      }
      pos++;
    }
    cout << time << endl;
  }

  return 0;
}