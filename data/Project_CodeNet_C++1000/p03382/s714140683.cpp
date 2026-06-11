#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  sort(a, a + n);
  int ans1 = a[n-1];
  int ans2 = 0;
  int diff = 2 * 1e9;
  for (int i=0; i<n; i++) {
    int tmp = min(abs(a[i]-ans1/2), abs(a[i]-(ans1+1)/2));
    if (tmp < diff) {
      ans2 = a[i];
      diff = tmp;
    }
  }
  cout<<ans1<<" "<<ans2<<endl;
}