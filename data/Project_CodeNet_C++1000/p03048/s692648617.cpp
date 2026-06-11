#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int a,b,c;  cin>>a>>b>>c;
  int n; cin>>n;
  int x,y,ans=0;
  rep(x,n/a+1){
    rep(y,n/b+1){
      if(n >= a*x + b*y && (n-a*x-b*y) % c == 0){ans++;}
    }
  }
  cout<<ans<<endl;
}