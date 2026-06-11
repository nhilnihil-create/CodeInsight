#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,h,w;
  cin >> n>>h>>w;
  vector<int>a(n),b(n);
  rep(i,n){
    cin>>a.at(i)>>b.at(i);
  }
  int ans=0;
  rep(i,n){
    if(a.at(i)>=h&&b.at(i)>=w){
      ans++;
    }
  }
  
 
  cout<<ans<<endl;  
}

