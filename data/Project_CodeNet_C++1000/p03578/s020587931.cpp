#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m;
  cin>>n;
  map<int,int> d;
  rep(i,n){
    int D;cin>>D;
    d[D]++;
  }
  cin>>m;
  bool ans=1;
  rep(i,m){
    int T;cin>>T;
    if(d[T]>0)d[T]--;
    else ans=0;
  }
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}

