#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5+200;
set<ll> a;
int main(){
    ll n,m;
    cin>>n>>m;
    double x = 1.0/n;
    ll a = pow(m,x) +1;
    // cout<<a<<endl;
    for(ll i = a; i >= 1; i--){
      if(m % (ll)pow(i,n) == 0){
        cout<<i<<endl;
        break;
      }
    }
}
