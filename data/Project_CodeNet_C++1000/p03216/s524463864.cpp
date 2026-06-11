#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,ll>>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N,Q;
  string S;
  cin>>N>>S>>Q;
  vector<int> k(Q);
  for(int i=0;i<Q;i++){
    cin>>k[i];
  }

  for(int i=0;i<Q;i++){
    ll D=0;
    ll M=0;
    ll num=0;
    vector<ll> count(N);
    for(int j=0;j<k[i];j++){
      if(S[j]=='D'){
        D++;
      }else if(S[j]=='M'){
        M++;
        num+=D;
      }
      count[j]=num;
    }
    for(int j=k[i];j<N;j++){
      if(S[j-k[i]]=='D'){
        D--;
        num-=M;
      }else if(S[j-k[i]]=='M'){
        M--;
      }
      if(S[j]=='D'){
        D++;
      }else if(S[j]=='M'){
        M++;
        num+=D;
      }
      count[j]=num;
    }

    ll ans=0;
    for(int j=1;j<N;j++){
      if(S[j]=='C'){
        ans+=count[j];
      }
    }

    cout<<ans<<endl;
  }
}
