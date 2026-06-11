#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using vll=vector<ll>;
using vi=vector<int>;
int main(){
  int n,i,ans=0;
  cin>>n;
  vi v(n),c(n);
  for(i=0;i<n;i++) cin>>v.at(i);
  for(i=0;i<n;i++){
    cin>>c.at(i);
    if(c.at(i)<v.at(i)) ans+=v.at(i)-c.at(i);
  }
  cout<<ans<<endl;
}