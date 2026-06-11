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
int main(){
  ll n;cin>>n;
  vector<T>vec;
  rep(i,n){
    ll a,b;cin>>a>>b;
    vec.push_back(make_tuple(a+b,a,b));
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  ll Takahashi=0;
  ll Aoki=0;
  rep(i,n){
    if(i%2==0)Takahashi+=get<1>(vec[i]);
    else Aoki+=get<2>(vec[i]);
  }
  cout<<Takahashi-Aoki<<endl;
}
