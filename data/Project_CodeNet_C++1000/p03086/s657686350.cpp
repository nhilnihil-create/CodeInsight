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
  int cnt = 0;
  int maxx = 0;
  for(int i = 0; i < S.size(); i++){
    if(S[i] != 'A' &&S[i] != 'C' &&S[i] != 'G'&&S[i] != 'T' ){
      if(cnt > maxx){
        maxx = cnt;
      }
      cnt = 0;
    } else{
      cnt++;
    }
  }
  cout << max(maxx, cnt) <<endl;
}
