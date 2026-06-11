#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int64_t f(int64_t x){
  int64_t cnt=(x+1)/2;
  int64_t ans=cnt%2;
  if(x%2==0){ans^=x;}
  return ans;
}
int main(){
  int64_t A,B;
  cin>>A>>B;
  int64_t ans=f(B)^f(A-1);
  cout<<ans<<endl;
  return 0;
}