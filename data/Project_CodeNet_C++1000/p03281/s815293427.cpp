#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[110][110000];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int checker(int n){
  int pre=0;
  for(int j=1;j<=n;j++){
    if((n%j)==0){
      pre++;
    }
  }
  return pre;
}

int main(){
  int n;
  cin >> n;
  int ans=0;
  for(int i=1;i<=n;i+=2){
    int tmp = checker(i);
    if(tmp==8){
      ans++;
    }
  }
  cout << ans << endl;
}
