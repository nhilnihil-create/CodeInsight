#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int sm=0; for(int i=0;i<n;i++) sm+=a[i];
  int mn=1e9, id=-1;
  for(int i=0;i<n;i++) {
    if (abs(sm-a[i]*n)<mn) mn=abs(sm-a[i]*n), id=i;
  }
  cout<<id<<endl;
}
