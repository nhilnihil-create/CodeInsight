#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  string S, T;
  cin >> S >> T;
  for(int i = 0; i < S.size(); i++){
    if(S == T){
      cout << "Yes" <<endl;
      return 0;
    } else{
      char s = S[S.size()-1];
      S.insert(S.begin(), s);
      S.erase(S.size()-1);
    }
  }
  cout << "No" <<endl;
}