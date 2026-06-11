#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N;
vector<ll> L,R;

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
      int l,r;
      cin>>l>>r;
      L.push_back(l);
      R.push_back(r);
  }
  L.push_back(0ll);
  R.push_back(0ll);
  sort(L.begin(),L.end());
  reverse(L.begin(),L.end());
  sort(R.begin(),R.end());
  ll ans=0;
  for(int i=0;i<N;i++){
      ans+=max(L[i]-R[i],0ll)*2;
  }
  cout<<ans<<endl;

  return 0;
}
