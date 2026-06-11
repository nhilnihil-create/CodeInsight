#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std; typedef long long ll; const int INF=1e9;
typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll an=0; map<ll,ll> mp; mp[0]=1;
  ll sm=0;
  for(int i=0;i<n;i++) {
    sm += a[i];
    an += mp[sm]; mp[sm]++;
    //for(P x:mp) cout<<"("<<x.first<<","<<x.second<<") "; cout<<endl;
  }
  cout<<an<<endl;
}