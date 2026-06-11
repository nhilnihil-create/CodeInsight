#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),B(N);
  vector<pair<ll,ll>> sum(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i)>>B.at(i);
    sum.at(i).first=A.at(i)+B.at(i);
    sum.at(i).second=A.at(i);
  }
  sort(sum.begin(),sum.end());
  reverse(sum.begin(),sum.end());
  ll ans=0;
  for(int i=0;i<N;i++){
    if(i%2==0){
      ans+=sum.at(i).second;
    }else{
      ans-=sum.at(i).first-sum.at(i).second;
    }
  }
  cout<<ans<<endl;
}
