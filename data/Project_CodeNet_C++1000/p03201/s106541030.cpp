#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(rng(A));
  reverse(rng(A));
  ll ans=0;
  map<int,int>m;
  for(auto it:A)m[it]++;
  for(int i=0;i<N;i++){
    int x=log2(A[i])+1;
    int y=(1ll<<x);
    m[A[i]]--;
    if(m[y-A[i]]>0&&m[A[i]]>=0){
      m[y-A[i]]--;
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
