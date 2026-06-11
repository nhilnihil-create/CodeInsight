#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(void){
  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }
  vector<P> ab(n);
  for(int i=0;i<n;i++){
    ab[i]=make_pair(a[i],b[i]);
  }
  sort(ab.begin(),ab.end());
  ll ans=0;
  for(int i=0;i<n;i++){
    ll num=min(m,ab[i].second);
    ans+=num*ab[i].first;
    m-=num;
  }
  cout<<ans<<endl;
  return 0;
}