//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  string n;cin>>n;
  ll sum=0;
  if(n=="10"||n=="100"||n=="1000"||n=="10000"||n=="100000"){
    cout<<10<<endl;
    return 0;
  }
  rep(i,n.size())sum+=n[i]-'0';
  cout<<sum<<endl;
}