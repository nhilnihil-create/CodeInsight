#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n;
  cin>>n;
  vector<int>a(n),c;
  vector<bool>b(n,true);
  rep(i,n) {
    cin>>a[i];
  }
  bool ex=true;
  while(ex){
    int co=0;
    int now=-1;
    rep(i,n){
      if(b[i]){
        co++;
        if(co==a[i]){
          now=i;
        }
      }
    }
    if(now>=0){
      b[now]=false;
      c.push_back(a[now]);
    }
    else{
      ex=false;
    }
  }
  if(c.size()==n){
    rep(i,n){
      cout<<c[n-1-i]<<endl;
    }
  }
  else{
    cout<<-1<<endl;
  }
}