#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  vector<int> A(4);
  rep(i,4) cin >> A[i];
  sort(A.begin(),A.end());
  if(A[0] == 1 && A[1] == 4 && A[2] == 7 && A[3] == 9){
    puts("YES");
  }
  else puts("NO");
  return 0;
}
