#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  int a,b;
  cin>>a>>b;
  //////
  int ans=0;
  ans+=a-1;
  if(a<=b) ans++;
  cout<<ans<<endl;
}