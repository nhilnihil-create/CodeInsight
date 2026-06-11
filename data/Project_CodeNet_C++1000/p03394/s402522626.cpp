#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  if (N == 3){
    cout << 2 << ' ' << 5 << ' ' << 63 << endl;
  } else if (N == 4){
    cout << 2 << ' ' << 3 << ' ' << 4 << ' ' << 9 << endl;
  } else {
    vector<int> ans;
    int M = N / 8;
    for (int i = 0; i < M; i++){
      ans.push_back(i * 12 + 2);
      ans.push_back(i * 12 + 3);
      ans.push_back(i * 12 + 4);
      ans.push_back(i * 12 + 6);
      ans.push_back(i * 12 + 8);
      ans.push_back(i * 12 + 9);
      ans.push_back(i * 12 + 10);
      ans.push_back(i * 12 + 12);
    }
    int K = N % 8;
    if (K != 0){
      ans.push_back(M * 12 + 6);
      if (K % 2 == 0){
        ans.push_back(M * 12 + 12);
      }
      if (K >= 3){
        ans.push_back(M * 12 + 2);
        ans.push_back(M * 12 + 4);
      }
      if (K >= 5){
        ans.push_back(M * 12 + 3);
        ans.push_back(M * 12 + 9);
      }
      if (K >= 7){
        ans.push_back(M * 12 + 8);
        ans.push_back(M * 12 + 10);
      }
    }
    for (int i = 0; i < N; i++){
      cout << ans[i];
      if (i < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}