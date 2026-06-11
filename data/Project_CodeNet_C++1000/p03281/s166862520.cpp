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
  cin >> N;
  int ans = 0;
  for(int i = 1; i <= N; i+=2){
    int cnt = 0;
    for(int j = 1; j <= i; j++){
      if(i % j == 0){
        cnt++;
      }
    }
    if(cnt == 8){
      ans++;
    }
  }
  cout << ans <<endl;
}