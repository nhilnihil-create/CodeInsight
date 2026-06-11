#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;

int main (){
   int n,m;
  cin >> n;
  vector<ll> d(n);
  rep(i,n)cin >> d[i];

  cin >> m;
  vector<ll> t(m);
  rep(i,m)cin >> t[i];

  map<ll,int> mpd,mpt;
  rep(i,n)mpd[d[i]]++;
  rep(i,m)mpt[t[i]]++;


  rep(i,m){
     ll x=t[i];
     if(mpt[x] > mpd[x] ){
      cout << "NO" <<endl;
      return 0;
     }
    }
  cout << "YES"  <<endl;

}
