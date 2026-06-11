#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  for (int i = 0; i < N - 8; i++){
    cout << S.at(i);
  }
}