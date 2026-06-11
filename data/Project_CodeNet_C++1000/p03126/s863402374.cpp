#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;

  vector<int> K(N);
  vector<vector<int>> A(N, vector<int>(M));
  bool all;
  int cnt = 0;

  for (int i = 0; i < N; i++){
    cin >> K.at(i);
    for (int j = 0; j < K.at(i); j++){  
      cin >> A.at(i).at(j);
    }
  }

  for (int i = 0; i < M; i++){
    all = true;
    for (int j = 0; j < N; j++){
      if (find(A.at(j).begin(), A.at(j).end(), i + 1) == A.at(j).end()) all = false; 
    }
    if (all){
      cnt += 1;
    }
  }

  cout << cnt << endl;
}