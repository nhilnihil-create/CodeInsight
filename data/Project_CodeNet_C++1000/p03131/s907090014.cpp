#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll k,a,b;
  cin >> k >> a >> b;
  if(b-a>=2){
    if(k>a){
      ll z=k-(a-1);
      cout << (a-1)+(z/2*(b-a)+z%2)+1 << endl;
    }
    else{
      cout << k+1 << endl;
    }
  }
  else{
    cout << k+1 << endl;
  }
}