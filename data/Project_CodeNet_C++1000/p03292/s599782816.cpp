#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A[3], ans;
  for(int i = 0; i < 3; i++)
    cin >> A[i];
  sort(begin(A),end(A));
  ans = A[2] - A[0];
  cout << ans << "\n";
  return 0;
}
