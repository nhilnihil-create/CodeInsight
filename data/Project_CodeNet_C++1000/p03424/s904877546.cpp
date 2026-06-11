#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //repマクロ

int main() {
  string S[100];
  int N;
  int type=3;
  cin >> N;
  rep(i,N){
    cin >> S[i];
    if(S[i] == "Y"){
        type=4;
    }
  }
  if (type==3)
    cout << "Three" <<endl;
  if (type==4)
    cout << "Four" <<endl;


}
