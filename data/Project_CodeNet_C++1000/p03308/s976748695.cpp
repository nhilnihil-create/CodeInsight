#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  vector<int> A(N);
  cin >> N;
  for(int i=0;i<N;i++) cin >> A[i];
  int mx=A[0];
  int mn=A[0];
  for(int i=0;i<N;i++){
    if(mx<A[i]) mx=A[i];
    if(mn>A[i]) mn=A[i];
  }

  cout << mx-mn <<endl;
}