#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> list(5);
  int t,j=0,mw=0;
  for(int i=0; i<5; i++) {
    cin >> list.at(i);
    t = 10-(list.at(i)%10);
    if(j < t && t != 10) {
      j = t;
      mw = i;
    }
  }
  int ans=0,x;
  for(int i=0; i<5; i++) {
    if(i != mw) {
      x = list.at(i);
      if(x%10 != 0) {
        x = (x+10)/10*10;
      }
      ans += x;
    }
  }
  ans += list.at(mw);
  cout << ans << endl;
}