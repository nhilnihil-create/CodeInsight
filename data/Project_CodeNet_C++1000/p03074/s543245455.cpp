#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
#define MOD 998244353

int main(){
  ll N,K;
  string S;
  cin>>N>>K>>S;
  vector<ll>A;
  vector<ll>B;
  ll i=0;
  if(S[0]=='0'){A.push_back(0);}
  while(i<N){
  	if(S[i]=='1'){
      ll a=1;
      int flag=0;
      while(flag==0){
        i++;
        if(i==N){break;}
        if(S[i]=='1'){a+=1;}
        if(S[i]=='0'){flag=1;}
      }
      A.push_back(a);
    }
  	else{
      ll b=1;
      int flag=0;
      while(flag==0){
        i++;
        if(i==N){break;}
        if(S[i]=='0'){b++;}
        if(S[i]=='1'){flag=1;}
      }
      B.push_back(b);
    }
  }
  if(S[N-1]=='0'){A.push_back(0);}
  ll ans=0;
  ll sum=0;
  if(B.size()<=K){cout<<N;return 0;}
  if(A.size()>B.size()){
    rep(j,K){sum=sum+A[j]+B[j];}
    sum+=A[K];
    ans=sum;
    for(ll j=K;j<B.size();j++){
      sum=sum-A[j-K]-B[j-K];
      sum=sum+A[j+1]+B[j];
      ans=max(ans,sum);
    }
  }
  cout<<ans;
}