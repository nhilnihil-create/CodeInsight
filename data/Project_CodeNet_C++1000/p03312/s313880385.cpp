#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n+1);
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++) a[i]+=a[i-1];
  LL ans=LINF;
  for(int i=2;i<=n-2;i++){
    int p=distance(a.begin(),lower_bound(a.begin(),a.begin()+i,a[i]/2));
    int q=distance(a.begin(),lower_bound(a.begin()+i,a.end(),(a[n]+a[i])/2));
    for(int x=p-1;x<=p+1;x++){
      for(int y=q-1;y<=q+1;y++){
        ans=min(ans,max(max(a[x],a[i]-a[x]),max(a[y]-a[i],a[n]-a[y]))
        -min(min(a[x],a[i]-a[x]),min(a[y]-a[i],a[n]-a[y])));
      }
    }
  }
  cout << ans << endl;
  return 0;
}