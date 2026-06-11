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
  int t;
  cin >> t;
  rep(i,t){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<b){
      cout << "No" << endl;
      continue;
    }
    if(b>d){
      cout << "No" << endl;
      continue;
    }
    if(c>=b-1){
      cout << "Yes" << endl;
      continue;
    }
    a=a%b;
    d=d%b;
    if(d==0){
      if(a<=c)cout << "Yes" << endl;
      else cout << "No" << endl;
      continue;
    }
    ll k=gcd(b,d);
    if(b-1-(b-1-a)%k<=c){
      cout << "Yes" << endl;
    }
    else cout << "No" << endl;
  }
}  
