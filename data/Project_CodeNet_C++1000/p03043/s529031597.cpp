#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  double N,K;
  cin>>N>>K;
  double ans=0;
  for(int i=1;i<=N;i++){
    int x=i;
    double p=1;
    int cnt=0;
    while(x<K){
        cnt++;
        x*=2;
        p/=2;
    }
    ans+=(1/N)*p;
  }
  cout<<fixed<<setprecision(15)<<ans<<endl;
  return 0;  
}