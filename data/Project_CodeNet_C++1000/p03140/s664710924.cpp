#include<iostream>
using namespace std;

main(){
  int N;
  cin >> N;
  char A[N],B[N],C[N];
  cin >> A >> B >> C;
  int ans=0;
  for(int ii=0;ii<N;ii++){
    if(A[ii]==B[ii] && B[ii]==C[ii])ans+=0;
    else if(A[ii]==B[ii] || B[ii]==C[ii] || A[ii]==C[ii])ans++;
    else ans+=2;
  }
  cout << ans << endl;
}
