#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  int64_t ans= 0;
  int64_t offset= 0;
  for(size_t i=0; i<S.size(); i++){
    if(S.at(i)=='W'){
      ans+= i- offset;
      offset++;
    }
  }

  cout << ans << endl;
}