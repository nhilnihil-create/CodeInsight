#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  int ans=100000000;
  rep(i,s.size()-2){
    string t;
    t=s.substr(i,3);
    int u,dif;
    u=stoi(t);
    dif=abs(u-753);
    ans=min(ans,dif);
  }
  cout<<ans<<endl;
}