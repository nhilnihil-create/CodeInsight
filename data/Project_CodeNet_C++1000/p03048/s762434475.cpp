#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a,b,c,n;
  cin >> a>>b>>c>>n;
  
  long ans=0;
  rep(i,n/a+1){
    rep(j,(n-i*a)/b+1){
      if((n-i*a-j*b)%c==0){
        ans++;
      }
    }
  }
  
  
  cout<<ans<<endl;  
}

