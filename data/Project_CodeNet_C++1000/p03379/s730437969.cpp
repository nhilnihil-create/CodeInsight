#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  cin>>n;
  int x[n];
  P memo[n];
  for(int i=0;i<n;i++){
    cin>>x[i];
    memo[i]=make_pair(x[i],i);
  }
  sort(memo,memo+n);
  int shita=memo[n/2-1].first,ue=memo[n/2].first;
  for(int i=0;i<n;i++){
    if(x[i]<=shita) cout<<ue;
    else cout<<shita;
    cout<<endl;
  }
  return 0;
}
