#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

//全探索

int coin_pattern(int A, int B, int C, int X){
  vector<int> tmp(3);
  int cnt = 0;
  X /= 50;

  rep(i,A+1){
    tmp.at(0) = i*10;
    rep(j, B+1){
      tmp.at(1) = 2*j + tmp.at(0);
      rep(k, C+1){
        tmp.at(2) = k + tmp.at(1);
        if(tmp.at(2) == X) cnt++;
      }
    }
  }

  return cnt;
}

int main(){
  int A,B,C,X;
  cin >> A >> B >> C >> X;

  int counter = coin_pattern(A,B,C,X);

  cout << counter << endl;
}
