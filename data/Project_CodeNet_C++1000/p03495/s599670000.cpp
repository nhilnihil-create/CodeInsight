#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, a;
  cin >> n >> k;
  vector<int> A(200100);
  while(cin >> a) ++A[a];
  sort(A.begin(), A.end());
  int Ak = 0, idx = 0, ans = 0;
  for(int a : A) if(a) ++Ak;
  while(Ak > k){
    if(A[idx]){
      ans += A[idx];
      --Ak;
    }
    ++idx;
  }
  cout << ans << endl;
}