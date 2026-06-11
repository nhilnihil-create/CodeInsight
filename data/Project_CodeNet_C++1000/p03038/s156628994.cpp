#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>
#define int ll

main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  vector<P> p(m);
  rep(i,m){
    int b, c;
    cin >> b >> c;
    p[i] = make_pair(c,b);
  }
  sort(p.begin(),p.end());
  rep(i,n){
    if(a[i] < p[p.size()-1].first){
      a[i]=p[p.size()-1].first;
      p[p.size()-1].second--;
      if(p[p.size()-1].second==0)p.pop_back();
    }
  }
  //answer
  ll ans=0;
  rep(i,n){
    ans+=a[i];
  }
  cout<<ans<<endl;
}
