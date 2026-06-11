#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  if (a[0] != 0) {
    cout<<-1<<endl;
    return 0;
  }
  for (int i=0; i<n-1; i++) {
    if (a[i+1] > a[i]) {
      if (a[i+1] - a[i] != 1) {
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  long long ans = a[n-1];
  for (int i=n-2; i>=0; i--) {
    if (a[i+1] <= a[i]) {
      ans += a[i];
    }
  }
  cout<<ans<<endl;
}