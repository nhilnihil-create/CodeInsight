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
  int A, B, K;
  cin >> A >> B >> K;
  int cnt = 0;
  for(int i = min(A, B); i >= 0; i--){
    if(A % i == 0 && B % i == 0){
      cnt++;
      if(cnt == K){
        cout << i <<endl;
        return 0;
      }
    }
  }
}
