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
  ll h,w;
  cin >> h >> w;
  vvl a(h,vl(w));
  ll cnt=0;
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
      if(a[i][j]%2==1){
        cnt++;
      }
    }
  }
  if(cnt%2!=0){
    cnt--;
  }
  ll i=0,j=0;
  ll X=0;
  ll A=0;
    while(i<h){
    ll BX=i,BY=j;
    if(a[BX][BY]%2!=0){
      X++;
    }
    if(i%2==0){
      j++;
      if(j==w){
        i++;
        j=w-1;
      }
    }
    else if(i%2==1){
      j--;
      if(j==-1){
        i++;
        j=0;
      }
    }
    if(i==h){
      break;
    }
    if(X%2==1&&X<=cnt){
      A++;
    }
  }
  cout << A << endl;
  i=0,j=0,X=0;
  while(i<h){
    ll BX=i,BY=j;
    if(a[BX][BY]%2!=0){
      X++;
    }
    if(i%2==0){
      j++;
      if(j==w){
        i++;
        j=w-1;
      }
    }
    else if(i%2==1){
      j--;
      if(j==-1){
        i++;
        j=0;
      }
    }
    if(i==h){
      break;
    }
    if(X%2==1&&X<=cnt){
      cout << BX+1 << " " << BY+1 << " " << i+1 << " " << j+1 << endl;
    }
  }
}