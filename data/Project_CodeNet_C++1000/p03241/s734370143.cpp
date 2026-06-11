#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  ll m;
  cin >> m;
  ll ans=0;
  rep(i,320000){
    ll y=i+1;
    if(m%y==0&&m/y>=n)ans=max(ans,y);
    if(m%y==0&&y>=n)ans=max(ans,m/y);
  }
  cout << ans << endl;
}
