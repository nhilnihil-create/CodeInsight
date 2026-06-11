#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main(){
  int q;cin>>q;
  vector<int> prime(2e5,1);
  prime[0]=0,prime[1]=0;
  for(int i=2;i<2e5;i++){
    if(prime[i]){
      for(int j=i*2;j<2e5;j+=i)prime[j]=0;
    }
  }
  vector<int> a(2e5);
  rep(i,2e5){
    if(i%2==0)continue;
      if(prime[i]&&prime[(i+1)/2])a[i]=1;
    }
  vector<int> vec(2e5+1);
  rep(i,2e5)vec[i+1]=vec[i]+a[i];
  rep(i,q){
    int l,r;cin>>l>>r;
    r++;
    cout<<vec[r]-vec[l]<<endl;
  }
}