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
  int cnt = 0;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(4 * i + 7 * j == N){
        cout << "Yes" <<endl;
        return 0;
      }
    }
  }
  cout << "No" <<endl;
}