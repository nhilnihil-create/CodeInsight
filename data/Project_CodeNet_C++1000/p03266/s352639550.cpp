//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
int main(){
  ll n,k;cin>>n>>k;
  if(k%2!=0){
    cout<<(n/k)*(n/k)*(n/k)<<endl;
  }
  else {
    ll d=k/2;
    cout<<(n/k)*(n/k)*(n/k)+(n/d-n/k)*(n/d-n/k)*(n/d-n/k)<<endl;
  }
}