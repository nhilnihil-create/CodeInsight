#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> A(3);
  cin >> A[0] >> A[1] >> A[2];
  int ans = 0;
  sort(A.begin(),A.end());
  ans += (A[2]-A[0])/2;
  A[0] += ((A[2]-A[0])/2)*2;
  ans += (A[2]-A[1])/2;
  A[1] += ((A[2]-A[1])/2)*2;
  //cout << A[0] << " " << A[1] << " " << A[2] << endl;
  int r = A[2]*2-A[1]-A[0];
  if(r==0){
    cout << ans << endl;
  }else if(r==1){
    cout << ans+2 << endl;
  }else{
    cout << ans+1 << endl;
  }
}