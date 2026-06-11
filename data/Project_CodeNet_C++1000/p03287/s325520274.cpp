#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M;
  cin>>N>>M;
  ll ans=0;
  vector<int> B(N,0);
  unordered_map<int,int> mp;
  mp.insert(make_pair(0,1));
  for(int i=0; i<N; i++){
    ll a;
    cin>>a;
    if(i==0)
      B[i]=a%M;
    else{
      B[i]=B[i-1]+a;
      B[i]%=M;
    }
    int tmp=mp[B[i]];
    mp[B[i]]=tmp+1;
    ans+=tmp;
  }
  cout<<ans<<endl;
}
