#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  long n;
  cin>>n;
  
  long ans=1;
  long m=1;
  vector<long>a(n);
  rep(i,n){
    cin>>a.at(i);
    ans*=3;
    if(a.at(i)%2==0){
      m*=2;
    }
  }
  ans-=m;
  cout<<ans<<endl;
}

