#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  int x;

  cin >> S >> T;
  x = S.size();
  for(int i=0;i<=x;++i){
    S.insert(S.begin(),S.at(x-1));
    S.pop_back();
    if(S == T){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
