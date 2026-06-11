#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int B = 0;
  string S;
  rep(i, N){
   cin >> S;
   if(S == "Y"){
    B = 1;}
  }
  if(B == 0){
  cout << "Three" <<endl;
  }
  if(B == 1){
  cout << "Four" <<endl;
  }
}