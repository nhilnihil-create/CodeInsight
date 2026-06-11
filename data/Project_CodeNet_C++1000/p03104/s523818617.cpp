#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t A,B,ans=0; cin>>A>>B;
  auto C=B-A+1;
  if(A%2==1){
    ans=(ans^A);
    C--;
  }
  if(B%2==0){
    ans=(ans^B);
    C--;
  }
  C/=2;
  if(C%2==1) ans=(ans^1);
  cout<<ans;
}
