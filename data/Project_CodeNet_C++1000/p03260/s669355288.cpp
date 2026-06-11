#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A,B;
  cin >> A >> B;

  for (int i = 1; i < 4; i++){
    if (A * B * i % 2 == 1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}