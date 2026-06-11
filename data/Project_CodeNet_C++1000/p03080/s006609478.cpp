#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int c = 0;
  for (int i = 0; i < N; i++){
    if (S[i] == 'R'){
      c++;
    } else {
      c--;
    }
  }
  cout << (c > 0 ? "Yes" : "No");
}