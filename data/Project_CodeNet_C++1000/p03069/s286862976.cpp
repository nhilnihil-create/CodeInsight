#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin >> N;
  string S;cin >> S;
  int Bsum = 0;
  vector<int> B(N,0);
  if(S[0]=='#'){
    B[0]=1;
    Bsum ++;
  }
  for(int i=1;i<N;i++){
    if(S[i]=='#'){
      B[i] = B[i-1] + 1;
      Bsum ++;
    }else{
      B[i] = B[i-1];
    }
  }
  int ans = N - Bsum;
  for(int i=0;i<N;i++){
    ans = min(ans,B[i]+N-i-1-(Bsum-B[i]));
  }
  ans = min(ans,Bsum);
  cout << ans << endl;
}