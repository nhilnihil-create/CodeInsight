
//In The Name Of GOD

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll mod = 1000000007;
const ll inf = 2000000000;
const ll infll = (ll)2*1000*1000*1000*1000*1000*1000;
const ll maxn = 20;
#define pb push_back
#define pp pop_back
#define IO ios_base::sync_with_stdio(false);

int main(){
  IO;
  ll x,y,z;
  cin>>x>>y;
  if(x%y==0){
    cout<<-1;
  }else if(2*x%y==0){
    cout<<3*x;
  }else{
    cout<<2*x;
  }
}
