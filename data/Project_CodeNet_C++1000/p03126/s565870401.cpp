#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (long long) (n); i++)
using ll=long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 1000000007;
// const int mod = 998244353;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<ll> v(m);
    rep(i,n){
      ll k;
      cin>>k;
      rep(j,k){
        ll p;
        cin>>p;
        v.at(p-1)+=1;
      }
    }

    ll a=0;
    rep(i,m){
      if(v.at(i)==n)a+=1;
    }
cout<<a;
}