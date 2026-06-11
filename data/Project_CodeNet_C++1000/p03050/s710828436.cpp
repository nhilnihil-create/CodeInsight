#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int64_t N;
  cin>>N;
  int64_t ans=0;
  for(int64_t i=1;i*i<=N;i++){
    if(N%i==0){
      int64_t m=N/i-1;
      if(m>0&&N/m==N%m){ans+=m;}
    }
  }
  cout<<ans<<endl;
  return 0;
}