#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  int n,k;
  cin>>n>>k;
  vin a(n);
  rep(i,n) cin>>a[i];
  ////
  int ans=0;
  ans++;
  n-=k;
  
  while(n>0){
    ans++;
    n-=(k-1);
    
  }
  cout<<ans<<endl;
}