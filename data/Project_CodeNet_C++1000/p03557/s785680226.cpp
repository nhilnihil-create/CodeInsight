#include <bits/stdc++.h>
using namespace std;

int a[100000],b[100000],c[100000];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(a, a+n);
  sort(c, c+n);
  long long ans = 0;
  for(int j = 0; j < n; j++){
    ans+=(c+n-upper_bound(c,c+n,b[j]))*(lower_bound(a,a+n,b[j])-a);
  }
  cout << ans << endl;
}