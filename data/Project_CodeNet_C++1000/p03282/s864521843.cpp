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
  int K;
  cin >> K;
  for(int i = 0; i < S.size(); i++){
    if(S[i] != '1'){
      cout << S[i] <<endl;
      return 0;
    }
    if(i == K-1){
      cout << '1' <<endl;
      return 0;
    }
  }
}