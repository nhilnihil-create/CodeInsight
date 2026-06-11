#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<int>a(n),l(n),r(n);
  rep(i,n){
    cin>>a.at(i);
  }
  l.at(0)=a.at(0);
  r.at(n-1)=a.at(n-1);
  rep2(i,1,n){
    l.at(i)=__gcd(l.at(i-1),a.at(i));
  }
  for(int i=n-2;i>=0;i--){
    r.at(i)=__gcd(r.at(i+1),a.at(i));
  }
  int ans=max(l.at(n-2),r.at(1));
  rep2(i,1,n-1){
    ans=max(ans,__gcd(l.at(i-1),r.at(i+1)));
  }
  cout<<ans<<endl;
}
            