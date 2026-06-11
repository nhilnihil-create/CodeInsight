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
int main(){
  string s;
  vector<string>vec;
  int k;
  cin>>s>>k;
  set<string>SET;
  int n=s.size();
  for(int i=1;i<=min(5,n);i++){
    for(int j=0;j+(i-1)<s.size();j++){
      SET.insert(s.substr(j,i));
    }
  }
  for(int i=0;i<k-1;i++)SET.erase(*begin(SET));
  cout<<*begin(SET)<<endl;
}