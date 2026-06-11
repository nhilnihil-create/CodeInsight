#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int n,k,ans=0;
  cin >> n >> k;
  int A[n];
  for(int i=0;i<n;++i) cin >> A[i];
  int backet[n];
  for(int i=0;i<n;++i) backet[i] = 0;
  for(int i=0;i<n;++i) {
    backet[A[i]]++;
  }
  sort(backet,backet+n,greater<int>());
  for(int i=0;i<k;++i) {
    ans += backet[i];
  }
  cout << n-ans << endl;
}