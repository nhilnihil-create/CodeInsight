#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const int INF = 1e9;
const double pi=acos(-1);


int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int>alp(26);
  rep(i,n)alp[s[i]-'a']++;
  ll ans=1;
  rep(i,26){
    if(alp[i]){
      ans*=(alp[i]+1);
      ans%=MOD;
    }
    
  }
  cout <<(ans-1+MOD)%MOD<<endl;
  
    
  return 0;
}
