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
  long double n,m,d;
  cin >> n >> m >> d;
  long double k=(n-d)*2/n/n;
  if(d==0)k/=2;
  cout << fixed << setprecision(13);
  cout << (m-1)*k << endl;
}  
