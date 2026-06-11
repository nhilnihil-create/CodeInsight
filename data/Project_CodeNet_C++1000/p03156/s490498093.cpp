#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
int main() {

int n,a,b;cin>>n>>a>>b;
  vector<ll>p(n);rep(i,n){cin>>p.at(i);}
  sort(all(p));
  
  int am=0,bm=0,cm=0;
  rep(i,n){if(p.at(i)<=a)am++;else{break;}}
  rep(i,n){if(p.at(i)<=b&&p.at(i)>a)bm++; if(p.at(i)>b){break;}}
  rep(i,n){if(p.at(i)>b)cm++;}
  int ans=min(am,bm);
  int answer=min(ans,cm);
  cout<<answer<<endl;
  
  
  
}
