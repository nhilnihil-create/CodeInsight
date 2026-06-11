#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
int inf=100000000;
const double PI = 3.14159265358979323846;
int main(){
  int m;
  cin >> m;
  int n;
  cin >> n;
  int k=2;
  rep(i,m)k*=2;
  int ans[k];
  if(n>k/2-1||(m==1&&n==1)){
    cout << -1 << endl;
    return 0;
  }
  if(m==1&&n==0){
    cout << 0 << " " << 0  << " " << 1 << " " << 1 << endl;
    return 0;
  }
  rep(i,k){
    if(i<k/2){
      if(i==n)ans[k/2-1]=n;
      else{
      if(i<n)ans[i]=i;
      else ans[i-1]=i;
      }
    }
    else{
      if(i-k/2==n)ans[k-1]=i-k/2;
      else{
        if(i-k/2>n)ans[k-1-(i-k/2)]=i-k/2;
        else ans[k-2-(i-k/2)]=i-k/2;
      }
    }
  }
  rep(i,k-1)cout << ans[i] << " ";
  cout << ans[k-1] << endl;
}  
