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
  for(int i = 0; i < 999; i++){
    if(N % 111 == 0){
      cout << N <<endl;
      return 0;
    }
    N++;
  }
}
