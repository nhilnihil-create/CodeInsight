#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> p;
  for (int i = 2; i <= N; i++){
    bool prime = true;
    for (int j = 2; j * j <= i; j++){
      if (i % j == 0){
        prime = false;
      }
    }
    if (prime){
      int tmp = 0;
      int N2 = N;
      while (N2 > 0){
        tmp += N2 / i;
        N2 /= i;
      }
      p.push_back(tmp);
    }
  }
  int C = p.size();
  int ans = 0;
  for (int i = 0; i < C; i++){
    if (p[i] >= 74){
      ans++;
    }
  }
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      if (i != j){
        if (p[i] >= 24 && p[j] >= 2){
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      if (i != j){
        if (p[i] >= 14 && p[j] >= 4){
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < C; i++){
    for (int j = i + 1; j < C; j++){
      for (int k = 0; k < C; k++){
        if (i != k && j != k){
          if (p[i] >= 4 && p[j] >= 4 && p[k] >= 2){
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}