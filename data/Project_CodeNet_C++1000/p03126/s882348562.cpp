#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>>KA(N, vector<int>(M+1));
  for(int i=0; i<N; i++){
    for(int j=0; j<M+1; j++){
      cin >> KA.at(i).at(j);
      if(KA.at(i).at(0)==j)break;
    }
  }
  
  vector<int>count(M+1);
  for(int i=0; i<N; i++){
    for(int j=1; j<KA.at(i).at(0)+1; j++){
      count.at(KA.at(i).at(j))++;
    }
  }
  
  int ans =0;
  for(int i=1; i<M+1; i++){
    if(count.at(i)==N)ans++;
  }
  
  cout << ans << endl;
}