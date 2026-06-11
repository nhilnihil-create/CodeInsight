#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int>count(N-1);
  vector<int>black(N);
  vector<int>white(N);
  int A = 0;
  int B = 0;
  
  for (int i = 0; i < N; i++){
    if (S.at(i) == '#'){
      A++;
    }
    else {
      B++;
    }
    black.at(i) = A;
    white.at(i) = B;
  }
  
  int sumb = black.at(N-1);
  int sumw = white.at(N-1);
  
  int ans = sumw;
  for (int i = 0; i < N; i++){
    if (ans > black.at(i) + sumw - white.at(i)){
      ans = black.at(i) + sumw - white.at(i);
    }
  }
  cout << ans << endl;
}
  
  
  
    
    


   
  
  




