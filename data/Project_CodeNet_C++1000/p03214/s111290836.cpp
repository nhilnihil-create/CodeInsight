#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a[110];

int main() {
  cin >> n;
  int sum=0;
  rep(i,n){
  cin >> a[i]; sum+=a[i];
  }
  double b=(double)sum/n,d=1000,ans=1000;
  for(int i=n-1;i>=0;i--){
    if(abs(a[i]-b)<d){
    d=abs(a[i]-b),ans=i;
    } else if(abs(a[i]-b)==d)
    ans=i;
  }
  cout << ans << endl;
}