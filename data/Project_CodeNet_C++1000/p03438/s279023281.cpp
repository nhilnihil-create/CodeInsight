#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  long long a=0;
  long long b=0;
  for(int i=0;i<N;i++){cin>>A[i];a+=A[i];}
  for(int i=0;i<N;i++){cin>>B[i];b+=B[i];}
  if(a>b){cout<<"No"<<endl; return 0;}
  long long c=b-a;
  long long d=0;
  for(int i=0;i<N;i++){
    if(A[i]-B[i]>0)d+=A[i]-B[i];
    else if((B[i]-A[i])%2==1)d++;
  }
  if(c<d){cout<<"No"<<endl; return 0;}
  cout<<"Yes"<<endl;
}