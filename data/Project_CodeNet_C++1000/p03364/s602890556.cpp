#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  char c[2*n][2*n];
  rep(i,n){
    string s;
    cin >> s;
    rep(j,n){
      char e=s[j];
      c[i][j]=e;
      c[n+i][j]=e;
      c[i][j+n]=e;
      c[n+i][j+n]=e;
    }
  }
  int ans=0;
  rep(i,n){
    int u=0;
    rep(j,n)rep(o,n)if(c[j][o+i]==c[o][j+i])u++;
    if(u==n*n)ans=ans+n;
  }
  cout << ans << endl;
}   
