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
  vin a(5);
  rep(i,5) cin>>a[i];
  int ans=0;
  int mn=10;
  rep(i,5){
   ans+=(a[i]+9)/10*10;
    if(a[i]%10!=0)
    mn=min(mn,a[i]%10);
    //cout<<ans<<endl;
  }
  cout<<ans-10+mn<<endl;
 
  
}