#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  for(int i=0;i<N;i++)cin>>A[i];
  B=A;
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    if(B[i]>=A[N/2])cout<<A[N/2-1]<<endl;
    else cout<<A[N/2]<<endl;
  }
}