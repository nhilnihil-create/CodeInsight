#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,m,c;
  cin >> n>>m>>c;
  vector<int>b(m);
  rep(i,m){
    cin>>b.at(i);
  }
  int ans=0;
  rep(i,n){
    int ch=c;
    vector<int>a(m);
    rep(j,m){
      cin>>a.at(j);
      ch+=a.at(j)*b.at(j);
    }
    if(ch>0){
      ans++;
    }
  }
  
  cout<<ans<<endl;
}