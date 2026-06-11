#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
  int n;
  cin >> n;
  vector<int> v(5);
  rep(i,n) {
    string s;
    cin >> s;
    if(s[0]=='M') v[0]++;
    if(s[0]=='A') v[1]++;
    if(s[0]=='R') v[2]++;
    if(s[0]=='C') v[3]++;
    if(s[0]=='H') v[4]++;
  }
  ll ans = 0;
  rep(i,3) {
    srep(j,i+1,4) {
      srep(k,j+1,5) {
        ans += (ll)v[i]*v[j]*v[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}