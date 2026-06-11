#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  for (int i=0; i<N; i++)cin>>A[i];
  int MAX=abs(A[0]-A[1]);
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      if (MAX<abs(A[i]-A[j])){
        MAX=abs(A[i]-A[j]);
      }
    }
  }
  cout<<MAX<<endl;
}

      