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
  ll h,w,n;
  cin >> h >> w >> n;
  ll sr,sc;
  cin >> sr >> sc;
  string s,t;
  cin >> s >> t;
  ll Rlim=w-sc,Llim=sc-1,Ulim=sr-1,Dlim=h-sr;
  ll r=0,l=0,u=0,d=0;
  rep(i,n){
    if(s[i]=='R'){
      r++;
    }
    else if(s[i]=='L'){
      l++;
    }
    else if(s[i]=='U'){
      u++;
    }
    else{
      d++;
    }
    if(r>Rlim||l>Llim||u>Ulim||d>Dlim){
      cout << "NO" << endl;
      return 0;
    }
    if(t[i]=='R'&&-l<Rlim)l--;
    if(t[i]=='L'&&-r<Llim)r--;
    if(t[i]=='U'&&-d<Ulim)d--;
    if(t[i]=='D'&&-u<Dlim)u--;
  }
  cout << "YES" << endl;
}