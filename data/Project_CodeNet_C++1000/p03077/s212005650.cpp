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
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll mn;
  mn=min(a,b);
  mn=min(min(c,d),min(mn,e));
  ////////////
  if(mn>n){
    cout<<5<<endl; 
  }
  else{
    ll ans=0;
    ans+=5;
    ans+=(n-1)/mn;
    cout<<ans<<endl;
  }
}