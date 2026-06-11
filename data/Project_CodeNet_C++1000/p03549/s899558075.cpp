#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m;
  cin>>n>>m;
  int ans;
  ans=(n-m)*100+m*1900;
  rep(i,m){
    ans*=2;
  }
  cout<<ans<<endl;
}

