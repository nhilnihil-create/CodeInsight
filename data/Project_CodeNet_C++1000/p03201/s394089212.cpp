#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());

  map<ll,int> mp;
  rep(i,N) mp[A[i]]++;
  int ans=0;
  int now=0;
  for(int i=30;i>=0;i--){
    int val=(1<<i);
    while(now<N&&A[now]>=val){
      int diff=(1<<(i+1))-A[now];
      if(diff==A[now]&&mp[A[now]]>=2){
        mp[A[now]]-=2;
        ans++;
      }
      if(diff!=A[now]&&mp[diff]>=1&&mp[A[now]]>=1){
        mp[diff]--;
        mp[A[now]]--;
        ans++;
      }
      now++;
    }
  }

  cout<<ans<<endl;

  return 0;
}
