#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    string S; cin>>S;
    if(S.at(0)=='M')A[0]++;
    if(S.at(0)=='A')A[1]++;
    if(S.at(0)=='R')A[2]++;
    if(S.at(0)=='C')A[3]++;
    if(S.at(0)=='H')A[4]++;
  }
  cout<<A[0]*A[1]*A[2]+A[0]*A[1]*A[3]+A[0]*A[1]*A[4]+A[0]*A[2]*A[3]+A[0]*A[2]*A[4]+A[0]*A[3]*A[4]+A[1]*A[2]*A[3]+A[1]*A[2]*A[4]+A[1]*A[3]*A[4]+A[2]*A[3]*A[4]<<endl;
}