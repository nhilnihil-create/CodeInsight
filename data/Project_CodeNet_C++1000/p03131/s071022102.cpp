#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll k,a,b;
  cin >> k >> a >> b;

  ll ans=1;
  if(a+1>=b) ans+=k;
  else if(a+1>k) ans+=k;
  else{
    ll rest = k-(a+1);
    ans = b + (b-a)*(rest/2) + rest%2;
  }

  cout << ans;
}