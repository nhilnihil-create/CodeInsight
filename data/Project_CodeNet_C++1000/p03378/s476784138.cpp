#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N,M,X;
  cin >> N >> M>> X;
  vector<int> A(M);
  for(int i=0;i<M;i++) cin >> A[i];
  auto itr=upper_bound(A.begin(),A.end(),X);
  int ans=min(A.end()-itr,itr-A.begin());
  cout << ans << endl;
}