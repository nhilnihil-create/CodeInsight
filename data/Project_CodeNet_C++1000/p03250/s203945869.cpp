#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  vector<int> A(3);
  rep(i,3) cin >> A[i];
  sort(A.rbegin(),A.rend());
  cout << A[0]*10 + A[1] + A[2] << endl;
  return 0;
}
