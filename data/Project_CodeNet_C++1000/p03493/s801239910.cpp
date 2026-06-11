#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  int cnt=0;
  vector<char> s(10);
  rep(i,3){
    cin >> s.at(i);
    if(s.at(i) == '1'){
      cnt++;
    }
  }
  
  
  cout << cnt << endl;
  
  return 0;
}
