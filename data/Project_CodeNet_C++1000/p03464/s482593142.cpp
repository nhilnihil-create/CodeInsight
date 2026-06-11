#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll k;
  cin >> k;
  ll a[k],l,r;
  for(int i=k-1;i>=0;i--){
    cin >> a[i];
  }
  l =  r = 2;
  for(int i=0;i<k;i++){
    if((l/a[i])*a[i]<l){
      l = (l/a[i])*a[i]+a[i];
    }
    r = (r/a[i])*a[i]+a[i]-1;
    if(r<a[i]||l>r){
      cout <<"-1\n";
      return 0;
    }
  }
  cout << l <<" "<<r<<endl;
}
