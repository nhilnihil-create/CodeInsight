#include <bits/stdc++.h>
using namespace std;
 
int main() {
int C,N,M,X;
C=0;
X=0;
cin>>N;
vector<string>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);}
cin>>M;
vector<string>B(M);
  for(int j=0;j<M;j++){
    cin>>B.at(j);}
    
 for(int k=0;k<N;k++){
  X=0;
   for(int l=0;l<N;l++){
    if(A.at(k)==A.at(l)){
      X++;}
   }
   for(int m=0;m<M;m++){
    if(A.at(k)==B.at(m)){
      X--;}
   } 
   if(X>=C){
     C=X;}  
  }
if(C<=0){
  cout << 0 << endl;}
else{
  cout << C << endl;}
  
}