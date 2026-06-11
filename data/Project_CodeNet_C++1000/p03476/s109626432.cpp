#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main(){
  int q;cin>>q;
  vector<int> p(2e5,1);
  p[0]=0,p[1]=0;
  for(int i=2;i<2e5;i++){
    if(p[i]){
      for(int j=i*2;j<2e5;j+=i)p[j]=0;
    }
  }
  vector<int> vec(2e5);
  rep(i,2e5){
    if(p[i]&&p[(i+1)/2])vec[i]=1;
  }
  vector<int> sum(2e5+1);
  rep(i,2e5)sum[i+1]=sum[i]+vec[i];
  rep(i,q){
    int l,r;cin>>l>>r;
    cout<<sum[r+1]-sum[l]<<endl;
  }
}