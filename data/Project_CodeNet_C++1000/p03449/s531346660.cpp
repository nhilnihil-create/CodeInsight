#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  for(int i = 0; i < n-1; i++) a[i+1] += a[i];

  int ans = 0;
  rep(i, n){
    int tmp;
    cin >> tmp;
    if(i == 0) ans = tmp+a[0];
    else{
      ans = max(ans+tmp, a[i]+tmp);
    }
  }
  cout << ans << endl;
}
