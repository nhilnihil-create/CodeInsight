#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n,x;
  cin>>n>>x;
  int mini=1000;
  rep(i,n){
    int m;
    cin>>m;
    x-=m;
    mini=min(mini,m);
  }
  cout<<n+x/mini<<endl;
}
