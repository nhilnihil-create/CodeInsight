#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,ans=0; string A,B,C;
  cin >> N >> A >> B >> C;
  for(int i=0; i<N; i++) {
    if(A[i]!=B[i] && A[i]!=C[i] && B[i]!=C[i]) ans+=2;
    else if(A[i]!=B[i] && A[i]!=C[i]) ans++;
    else if(A[i]!=B[i] && B[i]!=C[i]) ans++;
    else if(B[i]!=C[i] && A[i]!=C[i]) ans++;
  }
  cout << ans << endl;
}