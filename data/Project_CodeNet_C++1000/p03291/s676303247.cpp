#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000
#define MOD 1000000007
using Graph=vector<vector<int>>;

int main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<vector<ll>> sum(N+1,vector<ll>(4,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<4;j++){
      sum.at(i+1).at(j)=sum.at(i).at(j);
    }
    if(S.at(i)=='?'){
      sum.at(i+1).at(0)++;
    }else if(S.at(i)=='A'){
      sum.at(i+1).at(1)++;
    }else if(S.at(i)=='B'){
      sum.at(i+1).at(2)++;
    }else{
      sum.at(i+1).at(3)++;
    }
  }
  int Q=sum.at(N).at(0);
  ll num1=1,num2=1,num3=1,num4=1;
  for(int i=0;i<Q;i++){
    num1*=3;
    num1%=MOD;
  }
  for(int i=0;i<Q-1;i++){
    num2*=3;
    num2%=MOD;
  }
  for(int i=0;i<Q-2;i++){
    num3*=3;
    num3%=MOD;
  }
  for(int i=0;i<Q-3;i++){
    num4*=3;
    num4%=MOD;
  }

  ll ans=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='B'){
      ans+=sum.at(i).at(1)*(sum.at(N).at(3)-sum.at(i+1).at(3))%MOD*num1;
      ans%=MOD;
      ans+=sum.at(i).at(1)*(sum.at(N).at(0)-sum.at(i+1).at(0))%MOD*num2;
      ans%=MOD;
      ans+=sum.at(i).at(0)*(sum.at(N).at(3)-sum.at(i+1).at(3))%MOD*num2;
      ans%=MOD;
      ans+=sum.at(i).at(0)*(sum.at(N).at(0)-sum.at(i+1).at(0))%MOD*num3;
      ans%=MOD;
    }else if(S.at(i)=='?'){
      ans+=sum.at(i).at(1)*(sum.at(N).at(3)-sum.at(i+1).at(3))%MOD*num2;
      ans%=MOD;
      ans+=sum.at(i).at(1)*(sum.at(N).at(0)-sum.at(i+1).at(0))%MOD*num3;
      ans%=MOD;
      ans+=sum.at(i).at(0)*(sum.at(N).at(3)-sum.at(i+1).at(3))%MOD*num3;
      ans%=MOD;
      ans+=sum.at(i).at(0)*(sum.at(N).at(0)-sum.at(i+1).at(0))%MOD*num4;
      ans%=MOD;
    }
  }

  cout<<ans<<endl;
}
