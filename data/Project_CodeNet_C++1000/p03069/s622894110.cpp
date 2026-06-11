#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int count=0;
  vector<int> L(N+2, 0);
  vector<int> R(N+2, 0);
  for(int i=1; i<=N; i++){
    if(S[i-1]=='#'){
      L[i]=L[i-1]+1;
    }else{
      L[i]=L[i-1];
    }
  }
  for(int i=N; i>=1; i--){
    if(S[i-1]=='.'){
      R[i]=R[i+1]+1;
    }else{
      R[i]=R[i+1];
    }
  }
  int ans = 1e9;
  for(int i=0; i<=N; i++){
    ans = min(ans, L[i]+R[i+1]);
  }
  cout << ans << endl;
  return 0;
}