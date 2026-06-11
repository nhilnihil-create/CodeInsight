#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string S;
  cin>>S;
  ll sum=1, MOD=1000000007, A=0, AB=0, ABC=0;
  int i=-1;
  while(++i<S.length()){
    if(S[i]=='A')
      A+=sum;
    if(S[i]=='B')
      AB+=A;
    if(S[i]=='C')
      ABC+=AB;
    if(S[i]=='?'){
      ABC=ABC*3+AB;
      AB=AB*3+A;
      A=A*3+sum;
      sum*=3;
    }
    A%=MOD;
    AB%=MOD;
    ABC%=MOD;
    sum%=MOD;
  }
  cout<<ABC<<endl;
}
