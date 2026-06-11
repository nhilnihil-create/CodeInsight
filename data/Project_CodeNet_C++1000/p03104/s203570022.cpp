#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(int)n;i++)
#define rep2(i,l,r) for(ll i=l;i<(int)r;i++)

ll f(ll a){//aまでのxor
  if(a==0)return 0;
  if(a%2==1){
    if(a%4==1)return 1;
    else return 0;
  }
  else return a^f(a-1);
}


int main(){
  ll a,b;cin >> a >> b;
  if(a==0)cout << f(b);
  else cout << (f(a-1)^f(b));
  cout << endl;
}