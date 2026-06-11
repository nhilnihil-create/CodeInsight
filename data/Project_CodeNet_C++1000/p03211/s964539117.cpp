#include <bits/stdc++.h>
using namespace std;

int main() {

  string S;
  int ans = 800;
  
  cin >> S;
  for(int i=0;i<S.size() - 2;++i){
   	string T;
    T.push_back(S.at(i));
    T.push_back(S.at(i+1));
    T.push_back(S.at(i+2));
    int k = stoi(T);
    
    if(abs(753 - k) < ans) ans = abs(753 - k);
  }
  cout << ans << endl;
  return 0;
}
