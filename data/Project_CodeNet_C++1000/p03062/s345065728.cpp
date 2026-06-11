#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main() {
  int n,cnt=0; cin >> n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=abs(a[i]);
   if(a[i]<0)cnt++;
   a[i]=abs(a[i]);
  }

  if(cnt%2==0){
    cout << sum << endl;
  }
  else{
    sort(a.begin(),a.end());
    sum-=2*a[0];
    cout << sum << endl;
  }


}
