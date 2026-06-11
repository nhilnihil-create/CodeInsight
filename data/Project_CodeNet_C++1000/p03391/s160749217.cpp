#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin>>N;
  ll A[N+1]={},B[N+1]={};
  bool same=true;
  for(int i=0;i<N;i++){
      cin>>A[i]>>B[i];
      if(A[i]!=B[i]) same=false;
  }
  if(same){
      cout<<0<<endl;
      return 0;
  }

  ll resA=0,resB=0;
  vector<pair<ll,int>> v;
  for(int i=0;i<N;i++){
      if(A[i]<=B[i]){
          resA+=A[i];
          resB+=B[i];
      }else v.push_back(make_pair(B[i],i));
  }
  sort(v.begin(),v.end());
  ll ans=resA;

  for(int i=1;i<v.size();i++){
      ans+=A[v[i].second];
  }
  ans+=A[v[0].second]-B[v[0].second];
  cout<<ans<<endl;

  return 0;
}
