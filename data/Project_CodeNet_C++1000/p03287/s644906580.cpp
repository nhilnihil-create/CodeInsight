#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000000000

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> sum(N+1,0);
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    sum.at(i+1)=sum.at(i)+A;
    sum.at(i+1)%=M;
  }
  map<int,ll> m;
  for(int i=0;i<N+1;i++){
    if(m.count(sum.at(i))==0){
      m[sum.at(i)]=0;
    }
    m[sum.at(i)]++;
  }
  ll ans=0;
  for(auto x: m){
    ans+=x.second*(x.second-1)/2;
  }
  cout<<ans<<endl;
}
