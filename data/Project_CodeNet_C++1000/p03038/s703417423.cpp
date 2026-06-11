#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  int n,m;
  cin>>n>>m;
  priority_queue<int, vector<int>, greater<int>> a;
  vector<P> cb(m);
  rep(i,n){
    int w;
   cin>>w;
    a.push(w);
  }
  rep(i,m) {
    cin>>cb[i].second>>cb[i].first;
  }
  //////////
  sort(all(cb));
  reverse(all(cb));
  rep(i,m){
   int mn=a.top(); 
    int cnt=0;
    while(mn<cb[i].first&&cnt<cb[i].second){
      cnt++;
      a.pop();
      a.push(cb[i].first);
      mn=a.top();
    }
  }
  //
  ll ans=0;
  rep(i,n){
    ans+=a.top();
    //cout<<ans<<endl;
    a.pop();
  }
  cout<<ans<<endl; 
}