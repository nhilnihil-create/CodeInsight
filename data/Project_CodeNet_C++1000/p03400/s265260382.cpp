#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){cin >> A.at(i);}
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    ans = ans + (D-1)/A.at(i) + 1;}
  
  ans += X;
  
  cout << ans << endl;
    
}