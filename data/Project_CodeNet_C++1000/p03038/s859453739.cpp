#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  
  vector<pair<int, int>> CB;
  for (int i = 0; i < M; i++){
    int c, b;
    cin >> b >> c;
    CB.push_back({c, b});
  }
  
  sort(CB.begin(), CB.end());
  
  int pos = 0, Cpos = M - 1;
  while (pos < N && Cpos >= 0){
    int num = 0;
    while (num < CB.at(Cpos).second && pos < N){
      if (A.at(pos) < CB.at(Cpos).first){
        A.at(pos) = CB.at(Cpos).first;
        num++;
        pos++;
      }
      else{
        break;
      }
    }
    
    Cpos--;
  }
  
  
  long long int ans = 0;
  for (int i = 0; i < N; i++){
    ans += A.at(i);
  }
  
  cout << ans << endl;
}