#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,ans=-2000; cin >> A >> B;
  ans = max(ans,max(A+B,max(A-B,A*B)));
  cout << ans << endl;
}