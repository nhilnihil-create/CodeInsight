#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int N;
  cin >> N;
  
  vector<int>A(N);
  rep(i,N) cin >> A[i];
  sort(A.begin(),A.end());
  
  cout << A[N-1]-A[0] << endl;
  return 0;
  
}
