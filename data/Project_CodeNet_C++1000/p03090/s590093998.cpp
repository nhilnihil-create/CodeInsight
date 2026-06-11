#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;

  vector<vector<int>> e(110, vector<int>(110, 1));

  for(int i=1; i<=N; i++) e[i][i] = 0;

  int cnt = N*(N-1);
  if(N % 2 == 1){
    for(int i=1; i<=N; i++){
      e[i][N-i] = 0;
      if(i != N )cnt--;
    }
  } else {
    for(int i=1; i<=N; i++){
      e[i][N-i+1] = 0;
      cnt--;
    }
  }

  cout << cnt / 2   << endl;
  for(int i=1; i<=N; i++){
    for(int j=i+1; j<=N; j++){
      if(e[i][j] == 1) cout << i << " " << j << endl;
    }
  }
}


  
  