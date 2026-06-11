#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll x1,x2,y1,y2;
  cin>>x1>>y1>>x2>>y2;
  ll x3,x4,y3,y4;
  x3=x2+(y1-y2);
  x4=x1+(y1-y2);
  y3=y2-(x1-x2);
  y4=y1-(x1-x2);
  cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}