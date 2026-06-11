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
  ll h,w,n,sr,sc;
  cin >> h >> w >> n >> sr >> sc;
  sr--;sc--;
  string s,t;
  cin >> s >> t;
  ll L=0,R=w-1,U=0,D=h-1;
  bool a=true;
  for(ll i=n-1;i>=0;i--){
    if(i!=n-1){
      if(t[i]=='L'){
        R=min(R+1,w-1);
      }
      else if(t[i]=='R'){
        L=max(L-1,(ll)0);
      }
      else if(t[i]=='U'){
        D=min(D+1,h-1);
      }
      else{
        U=max(U-1,(ll)0);
      }
    }
    if(s[i]=='L'){
      L++;
    }
    else if(s[i]=='R'){
      R--;
    }
    else if(s[i]=='U'){
      U++;
    }
    else{
      D--;
    }
    if(U>D||L>R){
      a=false;
    }
  }
  if(L<=sc&&sc<=R&&U<=sr&&sr<=D&&a){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}