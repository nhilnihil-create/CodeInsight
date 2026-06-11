#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

vec Prime(1e7,0),W(1e7,0),isPrime(1e7+1,0);
void sosu(ll n){
  isPrime.at(0)=1;
  isPrime.at(1)=1;
  ll t=0;
  rep(i,n+1){
    if(isPrime.at(i)==0){
      Prime.at(t)=i;
      t++;
      for(ll j=2*i;j<=n;j+=i){
        isPrime.at(j)=1;
      }
    }
  }
}
void factor(ll M){
  rep(i,100000){
    if(Prime.at(i)==0){
      if(M==1) return;
      else{
        Prime.at(i)=M;
        W.at(i)++;
        M=1;
      }
    }else{
      while(M%Prime.at(i)==0){
        M/=Prime.at(i);
        W.at(i)++;
      }
    }
  }
}

int main(){
  ll N,a=0,b=0,c=0,d=0,e=0;
  cin >> N;
  sosu(N);
  rep(i,N){
    factor(i+1);
  }
  rep(i,N){
    if(Prime.at(i)!=0){
      if(W.at(i)>=2){
        a++;
      }
      if(W.at(i)>=4){
        b++;
      }
      if(W.at(i)>=14){
        c++;
      }
      if(W.at(i)>=24){
        d++;
      }
      if(W.at(i)>=74){
        e++;
      }
    }
  }
  ll ans=e+d*(a-1)+c*(b-1)+(b*(b-1)*(a-2))/2;
  cout << ans << endl;
}
          
          
        