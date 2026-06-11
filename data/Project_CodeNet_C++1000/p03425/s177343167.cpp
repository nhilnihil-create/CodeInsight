#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
long N, ans=0; cin >> N; string S; long A[5]={};
REP(i, N){
  cin >> S;
  if(S[0]=='M'){ A[0]++; }
  if(S[0]=='A'){ A[1]++; }
  if(S[0]=='R'){ A[2]++; }
  if(S[0]=='C'){ A[3]++; }
  if(S[0]=='H'){ A[4]++; }
}
ans+=A[0]*A[1]*A[2];ans+=A[0]*A[1]*A[3];ans+=A[0]*A[1]*A[4];
ans+=A[0]*A[2]*A[3];ans+=A[0]*A[2]*A[4];ans+=A[0]*A[3]*A[4];
ans+=A[1]*A[2]*A[3];ans+=A[1]*A[2]*A[4];ans+=A[1]*A[3]*A[4];
ans+=A[2]*A[3]*A[4];
cout << ans << "\n";
}