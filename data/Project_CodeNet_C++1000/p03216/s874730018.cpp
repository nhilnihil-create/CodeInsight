#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

int main(){
  int n; cin >>n;
  string s; cin >>s;
  int q; cin >>q;
  rep(_,q){
    int k; cin >>k;
    vector<vector<li>> dp(4,vector<li>(n+1,0));
    rep(i,n){
      dp[0][i+1]=(s[i]=='D')+dp[0][i];
      if(i-k+1>=0) dp[0][i+1]-=(s[i-k]=='D');
      dp[1][i+1]=(s[i]=='M')+dp[1][i];
      if(i-k+1>=0) dp[1][i+1]-=(s[i-k]=='M');
      dp[2][i+1]=(s[i]=='M')*dp[0][i+1]+dp[2][i];
      if(i-k+1>=0) dp[2][i+1]-=(s[i-k]=='D')*dp[1][i];
      dp[3][i+1]=(s[i]=='C')*dp[2][i+1]+dp[3][i];
    }
    if(df)rep(j,4)print(dp[j]);
    print(dp[3][n]);
  }
}
