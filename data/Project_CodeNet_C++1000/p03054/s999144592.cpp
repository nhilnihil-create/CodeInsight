#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w, n, sr, sc;
  string s, t;
  cin >> h >> w >> n >> sr >> sc >> s >> t;
  int lh=0, rh=h+1;
  int lw=0, rw=w+1;
  for(int i=n-1; i>=0; --i){
    if(t[i] == 'L') rw = min(w+1, rw+1);
    else if(t[i] == 'R') lw = max(0, lw-1);
    else if(t[i] == 'U') rh = min(h+1, rh+1);
    else if(t[i] == 'D') lh = max(0, lh-1);
    //cout << "(lh:" << lh << ",rh:" << rh << ") (lw:" << lw << ",rw:" << rw << ")" << endl;
    if(s[i] == 'L') ++lw;
    else if(s[i] == 'R') --rw;
    else if(s[i] == 'U') ++lh;
    else if(s[i] == 'D') --rh;
    //cout << "(lh:" << lh << ",rh:" << rh << ") (lw:" << lw << ",rw:" << rw << ")" << endl;
    if(lw+1 == rw || lh+1 == rh){
      cout << "NO" << endl;
      return 0;
    }
  }
  if(lh < sr && sr < rh && lw < sc && sc < rw){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}