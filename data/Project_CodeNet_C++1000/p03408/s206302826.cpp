#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string B[N];
  for(int i=0;i<N;i++) cin>>B[i];
  int M;
  cin>>M;
  string R[M];
  for(int i=0;i<M;i++) cin>>R[i];
  int A=0;
  for(int i=0;i<N;i++){
    int sum=0;
    for(int j=i;j<N;j++){
      if(B[i]==B[j]) sum++;
    }
    for(int k=0;k<M;k++){
      if(B[i]==R[k]) sum--;
    }
    A=max(A,sum);
  }
  cout<<A<<endl;
}