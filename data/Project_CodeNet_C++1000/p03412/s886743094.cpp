#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  int ans=0;
  for(int i=0;i<=28;i++){
    vector<vector<int>> c(2,vector<int>());
    for(int j=0;j<n;j++) c[(b[j]&(1<<i))/(1<<i)].push_back(b[j]&((1<<i)-1));
    sort(all(c[0]));
    sort(all(c[1]));
    LL one=0;
    int dist;
    for(int j=0;j<n;j++){
      dist=distance(c[0].begin(),lower_bound(all(c[0]),(1<<i)-(a[j]&((1<<i)-1))));
      if(a[j]&(1<<i)) one+=dist;
      else one+=c[0].size()-dist;
      dist=distance(c[1].begin(),lower_bound(all(c[1]),(1<<i)-(a[j]&((1<<i)-1))));
      if(a[j]&(1<<i)) one+=c[1].size()-dist;
      else one+=dist;
    }
    ans+=(one%2)*(1<<i);
  }
  cout << ans << endl;
  return 0;
}