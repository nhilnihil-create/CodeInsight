#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  vector<long long> v;
  for (int i=0; i<n; i++) {
    long long sum = 0;
    for (int j=i; j<n; j++) {
      sum += a[j];
      v.push_back(sum);
    }
  }
  for (int i=62; i>=0; i--) {
    vector<long long> nv;
    for (long long vi: v) {
      if ((vi >> i) & 1) {
        nv.push_back(vi);
      }
    }
    if (nv.size() >= k) {
      v = nv;
    }
  }
  long long ans = v[0];
  for (int i=1; i<v.size(); i++) {
    ans = ans & v[i];
  }
  cout<<ans<<endl;
}