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
  int ans = 0;
  vector<int> cosin(5);
  for(int i = 0; i < 5; i++){
    cin >> cosin[i];
    if(cosin[i] % 10 != 0){
      string s = to_string(cosin[i]);
      int x = s[s.size()-1] - '0';
      ans += cosin[i] + (10 - x);
    } else{
      ans += cosin[i];
    }
  }
  int min = 10;
  for(int i = 0; i < 5; i++){
    if(cosin[i] % 10 != 0){
      string s = to_string(cosin[i]);
      int x = s[s.size()-1] - '0';
      if(x < min){
        min = x;
      }
    }
  }
  cout << ans - (10 - min) <<endl;
}
