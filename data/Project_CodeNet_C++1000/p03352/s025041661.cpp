#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int x,ans=1;
  cin>>x;
  map<int,int> beki;
  for(int i=1; i*i<=1000; i++){
    for(int p=2; p<10; p++){
      beki[pow(i,p)]=1;
    }
  }
  rep(i,x+1){
    if(beki[i]==1){
      ans=i;
    }
  }
  cout<<ans<<endl;
}
