#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string T = "AKIHABARA";
  int N = T.size();
  bool ok = false;
  for (int i = 0; i < (1 << 4); i++){
    string T2;
    int cnt = 0;
    for (int j = 0; j < T.size(); j++){
      if (T[j] != 'A'){
        T2.push_back(T[j]);
      } else {
        if ((i >> cnt) & 1){
          T2.push_back(T[j]);
        }
        cnt++;
      }
    }
    if (S == T2){
      ok = true;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}