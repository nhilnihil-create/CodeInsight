#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n,m;
  cin>>n;
  map<int,int> memo1,memo2;
  for(int i=0;i<n;i++){
    int d;
    cin>>d;
    memo1[d]++;
  }
  cin>>m;
  for(int i=0;i<m;i++){
    int t;
    cin>>t;
    memo2[t]++;
  }
  bool ans=true;
  for(auto itr=memo2.begin();itr!=memo2.end();itr++){
    if(memo1[itr->first]<itr->second) ans=false;
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
