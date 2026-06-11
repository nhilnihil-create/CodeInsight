#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[110][110000];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  string s;
  cin >> s;
  int tmp = 0, ans = 0;
  rep(i,s.size()){
    if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
      tmp++;
    }else{
      chmax(ans,tmp);
      tmp=0;
    }
  }
  chmax(ans,tmp);
  cout << ans << endl;
}
