#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  string S;cin >> S;
  vector<int> L(N,0);
  for(int i=1;i<N;i++){
    if(S[i-1]=='W'){
      L[i] = L[i-1] + 1;
    }else{
      L[i] = L[i-1];
    }
  }
  vector<int> R(N,0);
  for(int i=N-2;i>=0;i--){
    if(S[i+1]=='E'){
      R[i] = R[i+1] + 1;
    }else{
      R[i] = R[i+1];
    }
  }
  int ans = N ;
  for(int i=0;i<N;i++){
    ans = min(ans,L[i] + R[i]);
  }
  cout << ans << endl;
}