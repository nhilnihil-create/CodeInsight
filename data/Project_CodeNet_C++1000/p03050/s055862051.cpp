#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  ll ans=0;
  rep(i,1000000){
    ll u=i+1;
    if(n-u<=0)continue;
    if((n-u)%u==0&&(n-u)/u>u)ans+=(n-u)/u;
  }
  cout << ans << endl;
}
