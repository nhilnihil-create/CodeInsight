#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) cin >> b[i];

  ll A,B;
  A=0;
  B=0;
  for(int i=0;i<n;++i){
    if(a[i]>b[i]) B+=a[i]-b[i];
    if(b[i]>a[i]) A+=(b[i]-a[i])/2;
  }
  if(A>=B) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
