#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define rALL(x) x.rbegin(),x.rend()

using namespace std;
using ll=long long;


int main(){
  int n;cin>>n;
  int z=1;
  rep(i,n)z*=3;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int cnt=0;
  for(auto x:a)if(x%2==0)cnt++;
  int t=1;
  rep(i,cnt)t*=2;
  cout<<(z-t);
}