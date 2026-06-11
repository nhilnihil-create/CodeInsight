#include<bits/stdc++.h>

using namespace std;

int main(){
  string S;
  cin >> S;
  
  int n = S.size();
  int K = n;
  
  for(int i = 1; i < n; i++){
    if(S[i] != S[i - 1]) K = min(max(i, n - i), K);
  }
  
  cout << K << endl;
  
  return 0;
}