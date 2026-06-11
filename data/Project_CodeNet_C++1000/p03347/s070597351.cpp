#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  ll k[n+1];
  k[0]=0;
  rep(i,n)cin >> k[i+1];
  ll ans=0;
  if(k[1]!=0){
    cout << -1 << endl;
    return 0;
  }
  rep(i,n){
    if(k[i]+1<k[i+1]){
      cout << -1 << endl;
      return 0;
    }
    if(k[i+1]==0)continue;
    if(k[i]+1==k[i+1])ans++;
    else{
      ans+=k[i+1];
    }
  }
  cout << ans << endl;
}  
