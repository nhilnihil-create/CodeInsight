#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;

int main() {
  int n,m,en=-100000,ans=0;
  cin >> n>>m;
  vector<P> p(m);
  rep(i,m){
    int a,b;
    cin >> a>>b;
    p[i]=P(b,a);
  }
  sort(p.begin(),p.end());
  rep(i,m){
    if(en<=p[i].second){
      en=p[i].first;
      ans++;
    }
  }
  cout <<ans<<endl;
}
