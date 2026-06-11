#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int ans=a+b+c;
  int ma=max(a,b);
  ma=max(ma,c);
  ans-=ma;
  while(k--){
    ma*=2;
  }
  ans+=ma;
  cout<<ans<<endl;
}
  



