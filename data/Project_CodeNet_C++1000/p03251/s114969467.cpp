#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X,Y; cin>>N>>M>>X>>Y;
  vector<int>A(N);
  vector<int>B(M);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<M;i++)cin>>B[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if(A[N-1]>=B[0]){cout<<"War"<<endl; return 0;}
  if(B[0]>X&&A[N-1]<Y){cout<<"No War"<<endl; return 0;}
  cout<<"War"<<endl;
}