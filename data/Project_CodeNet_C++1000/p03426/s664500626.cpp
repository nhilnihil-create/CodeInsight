#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w,d,a;cin>>h>>w>>d;
  map<ll,P> m;
  rep(i,h)rep(j,w) {cin>>a;m[a]=P(i+1,j+1);}
  lvector c(h*w+1,0);
  for(ll i=d+1;i<=h*w;++i) c[i]=c[i-d]+abs(m[i].first-m[i-d].first)+abs(m[i].second-m[i-d].second);
  ll q,l,r;cin>>q;
  rep(i,q) {
    cin>>l>>r;
    print(c[r]-c[l]);
  }
  return 0;
}
