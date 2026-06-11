#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B; string S;
  cin >> A >> B >> S;
  int N= A+1;
  int M= A+B+1;
  bool ans=true;
  
  for(int i=0; i<A; i++) {
    if(S[i]=='-') ans =false;
  }
  for(int i=N; i<M; i++) {
    if(S[i]=='-') ans =false;
  }
  if(S[A]!='-') ans=false;
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}