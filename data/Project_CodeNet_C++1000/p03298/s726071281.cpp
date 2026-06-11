#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;//res%=MOD;
    n*=n;//n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  int N;string s;cin>>N>>s;
  string t=s.substr(0,N);
  string u=s.substr(N,N);reverse(u.begin(),u.end());
  typedef pair<string,string> P;
  map<P,int> m;
  int ans=0;
  for(int i=0;i<pw(2,N);i++){
    string tmp1,tmp2;
    int j=i;
    for(int k=0;k<N;k++){
      if(j&1)tmp1+=t[k];
      else tmp2+=t[k];
      j/=2;
    }
    m[P(tmp1,tmp2)]++;
  }
  for(int i=0;i<pw(2,N);i++){
    string tmp1,tmp2;
    int j=i;
    for(int k=0;k<N;k++){
      if(j&1)tmp1+=u[k];
      else tmp2+=u[k];
      j/=2;
    }
    ans+=m[P(tmp1,tmp2)];
  }
  cout<<ans<<endl;
}
