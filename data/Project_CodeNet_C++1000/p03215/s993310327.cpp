#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n,k; cin>>n>>k;
  ll a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }
  vector<ll> v;
  for(int i=0;i<n;i++) {
    ll sm=0;
    for(int j=i;j<n;j++) {
      sm+=a[j];
      v.push_back(sm);
    }
  }
  /*
  for(int i=0;i<v.size();i++) {
    cout<<v[i]<<" ";
  } cout<<endl;*/
  ll an=0;
  for(ll x=(1LL<<60); x>0; x>>=1){
    int ct=0;
    for(int i=0;i<v.size()&&ct<k;i++) {
      if ((an+x & v[i]) == an+x) ct++;
    }
    if (ct == k) an += x;
  }
  cout<<an<<endl;
}