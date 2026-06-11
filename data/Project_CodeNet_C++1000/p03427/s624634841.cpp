#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  string n;
  cin >> n;
  ll k=n.size();
  bool b=false;
  rep(i,k-1){
    if(n[i+1]!='9'){
      b=true;
    }
  }
  if(b){
    cout << (n[0]-'0')+9*(k-1)-1 << endl;
  }
  else{
    cout << (n[0]-'0')+9*(k-1) << endl;
  }
}