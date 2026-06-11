#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  vector<string> c(2);
  rep(i,6){cin >> c[i];}
  
  reverse(c[1].begin(), c[1].end());
  
  if(c.at(0) == c.at(1)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}