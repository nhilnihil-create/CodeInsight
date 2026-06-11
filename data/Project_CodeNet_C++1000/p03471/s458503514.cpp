//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  ll n,y;
  cin>>n>>y;
  for(ll i=0;i<=n;i++){
    for(ll j=0;j+i<=n;j++){
      if(i*1000+j*5000+(n-i-j)*10000==y){
        cout<<n-i-j<<" "<<j<<" "<<i<<endl;
        return 0;
      }
    }
  }cout<<-1<<" "<<-1<<" "<<-1<<endl;
}
      
