#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int ans=1000000000;
  for(int i=0;i<n-k+1;i++){
    int j=i+k-1;
    int p=min(abs(a[i]),abs(a[j]));
    ans=min(ans,a[j]-a[i]+p);
  }
  cout << ans << endl;
}