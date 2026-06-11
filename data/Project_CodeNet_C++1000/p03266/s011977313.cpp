#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
#define MOD 1000000007
const int MAX = 510000;


int main(){
  ll n,k;
  cin>>n>>k;
  if(k%2==1){
    ll g=n/k;
    cout<<g*g*g;
  }
  else{
    ll g=n/k;
    ll h=(2*n)/k;
    h-=g;
    cout<<h*h*h+g*g*g;
  }
  
}
