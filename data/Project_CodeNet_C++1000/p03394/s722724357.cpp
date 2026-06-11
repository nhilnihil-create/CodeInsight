#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1LL<<50
#define fst first
#define snd second
#define pb push_back
#define int long long
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(int itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(int itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  if(n == 3){
    cout << "2 5 63" << endl;
    return 0;
  }
  
  if(n == 4){
    cout << "2 5 20 63" << endl;
    return 0;
  }
  
  if(n == 5){
    cout << "2 3 4 6 9" << endl;
    return 0;
  }
  
  int cnt = 0;
 // debug(check);
  while(n >= 6 && cnt != 2500){
      REP(i,12){
        if(((i+1)%2 == 0 || (i+1)%3== 0) && (i+1)%6 != 0) cout << (i+1)+cnt*12 << " ";
      }
      n -= 6;
      cnt++;
  }
  
  cnt = 1;
  while(n != 0){
    cout << cnt*6 << " ";
    n--;
    cnt++;
  }
  
  return 0;
}