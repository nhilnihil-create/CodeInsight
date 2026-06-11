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
  string s;
  cin >> s;
  ll k=s.size();
  if(k==26){
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
    }
    else{
      ll i=26;
      bool y=true;
      ll j;
      while(y&&i>0){
        if(s[i-1]<s[i]){
          j=i-1;
          y=false;
        }
        i--;
      }
      string t="";
      rep(i,j){
        t+=s[i];
      }
      //cout << t << endl;
      bool z;
      ll cnt=0;
      if(j!=0){
      rep(i,26){
        z=true;
        rep(k,j){
          if(s[k]==abc[i]){
            z=false;
          }
          else if(abc[i]<=s[j]){
            z=false;
          }
        }
        if(cnt==0){
          if(z){
            t+=abc[i];
            cnt++;
          }
        }
      }
      cout << t << endl;
    }
      if(j==0){
        char c=s[0];
        rep(i,25){
          if(c==abc[i]){
            c=abc[i+1];
            break;
          }
        }
        cout << c << endl;
      }
    }
  }
  else{
    char c;
    rep(i,26){
      c=abc[i];
      bool ok=true;
      rep(j,k){
        if(s[j]==c){
          ok=false;
        }
      }
      if(ok){
        break;
      }
    }
    cout << s << c << endl;
  }
}