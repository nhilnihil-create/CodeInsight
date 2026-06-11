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
  ll N,M,X,Y;
  cin>>N>>M>>X>>Y;
  vl x1(N);
  vl x2(M);
  rep(i,N) cin>>x1[i];
  rep(i,M) cin>>x2[i];
  sort(all(x1));
  sort(all(x2));
  if(x2[0]-x1[N-1]>0&&x1[N-1]<Y&&x2[0]>X){
    cout<<"No War"<<endl;
  }
  else{
    cout<<"War"<<endl;
  }
  
}
