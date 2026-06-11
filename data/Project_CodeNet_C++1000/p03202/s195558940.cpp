#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int tv = 200000;
  int fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    vector<tuple<int, int, int>> S;
    S.push_back(make_tuple(0, A[0], A[0]));
    bool ok = true;
    for  (int i = 1; i < N; i++){
      if (A[i] > A[i - 1]){
        S.push_back(make_tuple(0, A[i] - A[i - 1], A[i]));
      } else {
        while (get<2>(S.back()) > A[i]){
          if (get<2>(S.back()) - get<1>(S.back()) >= A[i]){
            S.pop_back();
          } else {
            get<1>(S.back()) -= get<2>(S.back()) - A[i];
            get<2>(S.back()) = A[i];
          }
        }
        int p = get<0>(S.back());
        bool upd = false;
        while (get<0>(S.back()) == mid - 1){
          S.pop_back();
          upd = true;
          if (S.empty()){
            ok = false;
            break;
          }
        }
        if (!ok){
          break;
        }
        get<1>(S.back())--;
        get<2>(S.back())--;
        int q = get<0>(S.back());
        if (get<1>(S.back()) == 0){
          S.pop_back();
        }
        if (upd){
          if (S.empty()){
            S.push_back(make_tuple(q + 1, 1, 1));
          } else {
            S.push_back(make_tuple(q + 1, 1, get<2>(S.back()) + 1));
          }
          if (get<2>(S.back()) < A[i]){
            S.push_back(make_tuple(0, A[i] - get<2>(S.back()), A[i]));
          }
        } else {
          if (S.empty()){
            S.push_back(make_tuple(p + 1, A[i], A[i]));
          } else {
            S.push_back(make_tuple(p + 1, A[i] - get<2>(S.back()), A[i]));
          }
        }
      }
      if (!ok){
        break;
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}