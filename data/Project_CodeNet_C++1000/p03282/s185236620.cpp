#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  ll k;
  cin>>k;
  int INF_n=1;
  int tmp;
  rep(i,s.size()){
    if(s[i]!='1'){
      INF_n=s[i]-48;
      tmp=i+1;
      break;
    }
  }
  int ans=1;
  if(INF_n!=1){
    if(k>=tmp){
      ans=INF_n;
    }
  }
  cout<<ans<<endl;
}