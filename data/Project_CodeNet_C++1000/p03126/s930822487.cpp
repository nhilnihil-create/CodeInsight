#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(0);
  for(int i = 0; i < N; i++){
    int K;
    cin >> K;
    vector<int> AK(K);
    for(int j = 0; j < K; j++){
      cin >> AK.at(j);
    }
    A.push_back(AK);
  }
  int cnt = 0, frag, dekafrag, K;
  for(int i = 1; i <= M; i++){
    int dekafrag = 0;
    for(int j = 0; j < N; j++){
      int frag = 0;
      K = A.at(j).size();
      for(int t = 0; t < K; t++){
        if(A.at(j).at(t) == i) frag = 1;
      }
      if(frag == 0) dekafrag = 1;
    }
    if(dekafrag == 0){
      cnt++;
    }
  }
  cout << cnt << endl;
}