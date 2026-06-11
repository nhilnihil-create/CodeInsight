#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] -= i+1;
  }
  sort(a.begin(),a.end());
  int m = a[a.size()/2];

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    a[i]-=m;
    a[i] = abs(a[i]);
    ans+=a[i];
  }
  cout << ans << endl;
}