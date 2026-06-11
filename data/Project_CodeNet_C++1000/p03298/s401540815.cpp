#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)





int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  map<pair<string, string >, ll> smap;
  rep(i,(1<<n)){
    string ss,tt;
    rep(j,n){
      if(i & (1<<j)) ss.pb(s[j]);
      else tt.pb(s[j]);
    }
    smap[mp(ss,tt)]++;      
  }
  ll ans=0;
  rep(i,(1<<n)){
    string ss,tt;
    rep(j,n){
      if(i & (1<<j)) ss.pb(s[2*n-1-j]);
      else tt.pb(s[2*n-1-j]);
    }
    ans += smap[mp(ss,tt)];
  }
  cout << ans << endl;
  //  cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s"<<endl;
  return 0;
    

}
