#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

vector<ll> Prime(10000,0);
void sosu(ll n){
  Prime.at(0)=2;
  ll t=1;
  for(ll i=3;i<n;i++){
    rep(j,t){
      if(i%Prime.at(j)==0){
        break;
      }
      if(j==t-1){
        Prime.at(t)=i;
        t++;
      }
    }
  }
}

int main(){
  ll N,a=0,b=0,c=0,d=0,e=0;
  cin >> N;
  sosu(N);
  vector<ll> W(N,0);
  rep(i,N){
    ll t=0,k=i+1;
    while(Prime.at(t)!=0){
      while(k%Prime.at(t)==0){
        W.at(t)++;
        k/=Prime.at(t);
      }
      t++;
    }
  }
  ll t=0;
  while(Prime.at(t)!=0){
    if(W.at(t)>=74){
      e++;
    }
    if(W.at(t)>=24){
      d++;
    }
    if(W.at(t)>=14){
      c++;
    }
    if(W.at(t)>=4){
      b++;
    }
    if(W.at(t)>=2){
      a++;
    }
    t++;
  }
  cout << e+d*(a-1)+c*(b-1)+(b*(b-1)*(a-2))/2 << endl;
}