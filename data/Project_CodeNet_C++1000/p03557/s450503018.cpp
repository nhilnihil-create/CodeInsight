#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a);
  sort(b);
  sort(c);
  ll ans = 0;
  rep(i,n){
    int ok = -1;
    int ng = n;
    while(abs(ok-ng)>1){
      int mid = (ok+ng)/2;
      if(a[mid]<b[i]) ok = mid;
      else ng = mid;
    }
    int arange = ok + 1;
    ok = n;
    ng = -1;
    while(abs(ok-ng)>1){
      int mid = (ok+ng)/2;
      if(c[mid]>b[i]) ok = mid;
      else ng = mid;
    }
    int crange = n - ok;
    ans += (ll)arange*crange;
  }
 cout << ans << endl; 
}
