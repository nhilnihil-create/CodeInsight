#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e15+4;
const int Nmax=2e5+1;
const int Nd=61;
ll dfs[3003][3003][4];
ll  v[3003][3003];


int main(){
  int n; cin>>n;
  vector<ll> a(n),b(n);
  ll sumA=0,sumB=0;
  ll now1=0,now2=0;

  rep(i,n) {
    cin>>a[i];
    sumA+=a[i];
  }
  rep(i,n) {
    cin>>b[i];
    
    sumB+=b[i];
    if(a[i]<b[i]){
      now1+=((b[i]-a[i]+1)/2);
    }else{
      now2+=a[i]-b[i];
    }

  }

  ll num=sumB-sumA;
  if(now1>num || now2>num){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
  return 0;


}
