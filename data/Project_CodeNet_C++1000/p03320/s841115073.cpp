#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll wa(ll X){
  ll res=0;
  while(X>0){
    res+=X%10;
    X/=10;
  }
  return res;
}

ll f(ll X){
  double MI=1.0*X/wa(X);
  ll mi=X,k=1;
  string S=to_string(X);
  reverse(S.begin(),S.end());
  rep(i,16){
    int num;
    if(i<S.length()){
      num=S[i]-'0';
      X-=num*k;
    }else{
      num=1;
    }
    for(int j=num+1;j<=9;j++){
      X+=j*k;
      if(1.0*X/wa(X)<MI){
        MI=1.0*X/wa(X);
        mi=X;
      }
      X-=j*k;
    }
    X+=9*k;
    k*=10;
  }
  return mi;
}

int main(){
  int K; cin>>K;
  ll x=1;
  rep(i,K){
    cout<<x<<endl;
    x=f(x+1);
  }
  return 0;
}
