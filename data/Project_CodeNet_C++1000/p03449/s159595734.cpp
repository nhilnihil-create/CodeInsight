#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int cnt1=0, cnt2=0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  int ans=0;
  for(int i=0; i<n; i++) {
    cnt1=0;
    for(int j=0; j<=i; j++) {
      cnt1+=a[j];
    }
    for(int k=i; k<n; k++) {
      cnt1+=b[k];
    }
    if(cnt1>=cnt2) {
      cnt2=cnt1;
    }
  }
  cout << cnt2 << endl;
}