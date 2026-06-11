#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,a[100],cnt=0,ans=0;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    cnt+=a[i];
  }
  for(int i=0; i<n; i++) {
    if(abs(a[i]*n-cnt)<abs(a[ans]*n-cnt)) {
      ans=i;
    }
  }
  cout << ans << endl;
}