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
  int n;
  cin >> n;
  int ans[n];
  int cnt=0;
  int k=3;
  while(cnt!=n){
    while(true){
      int u=0;
      rep(i,k){
        if(i>1&&k%i==0)u++;
      }
      if(u==0)break;
      else k+=10;
    }
    ans[cnt]=k;
    k+=10;
    cnt++;
  }
  rep(i,n-1)cout << ans[i] << " ";
  cout << ans[n-1] << endl;
}  
