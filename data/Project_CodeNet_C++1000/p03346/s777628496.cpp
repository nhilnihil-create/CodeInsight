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
  int k[n];
  rep(i,n){
    int u;
    cin >> u;
    k[u-1]=i;
  }
  int ma=1;
  int cnt=1;
  rep(i,n-1){
    if(k[i]<k[i+1]){
      cnt++;
    }
    else{
      cnt=1;
    }
    ma=max(ma,cnt);
  }
  cout << n-ma <<  endl;
}  
