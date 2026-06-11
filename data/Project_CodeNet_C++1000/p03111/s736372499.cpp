#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n,A,B,C;
  cin >> n >> A >> B >> C;

  vector<ll> l(8,0);
  ll ans = (ll)1e12;
  rep(i,n) cin >> l[i];
  for(ll i = 0; i <= 1<<16 ; i++){
    ll tmp = 0;
    
    ll a = 0,b = 0,c = 0;
    for(ll j = 0; j < n; j++){
        ll x = 0;
        x += (i>>(j*2))%2;
        x += ((i>>(j*2+1))%2)*2;
        if(x==0){
          if(a!=0) tmp += 10;
          a += l[j];
        }else if(x==1){
          if(b!=0) tmp += 10;
          b += l[j];
        }else if(x==2){
          if(c!=0) tmp += 10;
          c += l[j];
        }else{
          continue;
        }
    }
    if(a==0||b==0||c==0){
      continue;
    }else{
      // cout << a << " " << b <<  " " << c << endl; 
      tmp += abs(A-a)+abs(B-b)+abs(C-c);
      // if(tmp==10) cout << a << " " << b <<  " " << c << endl;
      // if(tmp==10) cout << abs(A-a)+abs(B-b)+abs(C-c) << endl;

      ans = min(ans,tmp);
    }
  }

  cout << ans << endl;

  return 0;
} 