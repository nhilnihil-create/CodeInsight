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
  int N;
  string S;
  cin >> N >> S;
  set<char> si, sj;
  int ans = 0;
  for(int i = 0; i < S.size(); i++){
    int cnt = 0;
    si.clear();
    sj.clear();
    for(int j = 0; j < S.size(); j++){
      if(j <= i){
        si.insert(S[j]);
      } else{
        sj.insert(S[j]);
      }
    }
    for(auto x: si){
      if(sj.count(x)){
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans <<endl;
}