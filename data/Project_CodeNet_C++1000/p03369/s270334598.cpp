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
  string S;
  cin >> S;
  int ans = 700;
  for(int i = 0; i < 3; i++){
    if(S[i] == 'o'){
      ans+=100;
    }
  }
  cout << ans <<endl;
}
