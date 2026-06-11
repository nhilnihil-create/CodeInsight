#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  vector<int>num(N);
  
  for (int i = 0; i < N; i++) {
    num.at(i) = S.at(i) - '0';
    num.at(i) -= 49;
  }
  
  int Min;
  int count = 0;
  
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < N; j++) {
      if (num.at(j) == i){
        break;
      }
      else if (j == N-1){
        Min = i;
        count++;
      }
    }
    if (count > 0){
      break;
    }
  }
  
  if (N != 26){
    cout << S;
    printf("%c", Min + 'a'); 
  }
  else {
    if (S == "zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
      return 0;
    }
    reverse(num.begin(), num.end());
    for (int i = 0; i < 25; i++) {
      if (num.at(i) > num.at(i+1)){
        for (int j = 0; j < 26-i-2; j++) {
          cout << S.at(j);
        }
        for (int k = 0; k <= i; k++) {
          if (num.at(k) >= num.at(i+1)){
            printf("%c", num.at(k) + 'a');
            break;
          }
        }
        cout << endl;
        return 0;
      }
    }
  }
}