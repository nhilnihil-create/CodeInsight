#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  int a=1;
  rep(i,m){
    a*=2;
  }
  int ans=(1900*m+100*(n-m))*a;
  cout<<ans<<endl;
}
