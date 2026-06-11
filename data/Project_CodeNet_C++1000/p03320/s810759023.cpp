#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int digit(ll x){
    int res=0;
    while(x>0){
        x/=10;
        res++;
    }
    return res;
}

int digitSum(ll x){
    int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}

ll f(ll N){
    vector<ll> cand;
    ll d=digit(N);
    cand.push_back(N);
    ll dwdig=0;
    for(int i=0;i<d-3;i++) dwdig=dwdig*10+9;
    ll ten=1;
    for(int i=0;i<d-3;i++) ten=ten*10;
    for(ll i=1;i<=9;i++){
        for(ll j=0;j<=9;j++){
            for(ll k=0;k<=9;k++){
                ll res=i*100*ten+j*10*ten+k*ten+dwdig;
                if(N>res) continue;
                cand.push_back(res);
            }
        }
    }

    int mit=0;
    for(int i=0;i<cand.size();i++){
        ll l=cand[mit];
        ll ls=digitSum(l);
        ll r=cand[i];
        ll rs=digitSum(r);
        if(rs*l>ls*r) mit=i;
    }
    return cand[mit];
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll K;
  cin>>K;
  vector<ll> ans;
  rep(i,9) ans.push_back(i+1);
  for(int i=19;i<=99;i+=10) ans.push_back(i);

  ll N=100;
  while(ans.size()<K){
      ll nex=f(N);
      ans.push_back(nex);
      N=nex+1;
  }
  rep(i,K) cout<<ans[i]<<endl;

  return 0;
}
