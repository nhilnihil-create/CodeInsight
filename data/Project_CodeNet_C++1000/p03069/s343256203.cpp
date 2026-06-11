#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> cumb(n+1);
  vector<int> cumw(n+1);
  cumb.at(0) = 0;
  for(int i=0; i<n; i++){
    if(s.at(i)=='#'){
      cumb.at(i+1) = cumb.at(i)+1;
    }else{
      cumb.at(i+1) = cumb.at(i);
    }
  }
  cumw.at(n) = 0;
  for(int i=0; i<n; i++){
    if(s.at(n-1-i)=='.'){
      cumw.at(n-1-i) = cumw.at(n-i)+1;
    }else{
      cumw.at(n-1-i) = cumw.at(n-i);
    }
  }
  int ans = 1000000000;
  for(int i=0; i<=n; i++){
    //cout << 'w' << cumw.at(i) << 'b' << cumb.at(i) <<endl;
    ans = min(ans, cumw.at(i)+cumb.at(i));
  }
  cout << ans <<endl;
}
      