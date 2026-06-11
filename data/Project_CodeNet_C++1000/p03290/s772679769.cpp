#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int d,g;
  cin >> d >> g;
  int k[d];
  int c[d];
  rep(i,d)cin >> k[i] >> c[i];
  int o=(1<<d);
  int ans=100000000;
  rep(i,o){
    //cout << 0 << i << endl;
    //cout << ans << endl;
    int cnt=0;
    int an=0;
    rep(j,d){
      if(i&(1<<j)){
        an+=c[j]+(j+1)*100*k[j];
        cnt+=k[j];
      }
    }
    if(an>=g){
      ans=min(ans,cnt);
      //if(cnt==54)cout << i << endl;
    }
    else{
      int y=d-1;
      while(i&(1<<y)){
        y--;
      }
      int cn=0;
      if((g-an-1)/(100*(y+1))+1>k[y]-1)continue;
      else ans=min(ans,cnt+(g-an-1)/(100*(y+1))+1);
      //if(cnt+(g-an-1)/(100*(y+1))+1==54)cout << i << endl;
    }
  }
  cout << ans << endl;
}  
