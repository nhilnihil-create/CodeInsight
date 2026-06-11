#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define for(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll =long long ;
typedef pair<int,int > P;


ll j=0;
ll t;
ll k;
ll d(ll x,ll y){
  if (j==k){
    return t+1;
  }
  if (x%t==0 &&y%t==0){
    j++;
    t--;
    d(x,y);
  }
  else{
    t--;
    d(x,y);
  }
}


int main(){
  ll a,b;
  cin>>a>>b>>k;
  t=a;
  cout<<d(a,b)<<endl;
}
