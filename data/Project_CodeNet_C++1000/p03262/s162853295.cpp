#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
using Graph=vector<vector<int>>;
using edge= struct{int to;ll cost;};
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
typedef priority_queue<ll> PQ_HIGH;
typedef priority_queue<ll,VL,greater<ll>> PQ_LOW;//昇順
ll gcd(ll x, ll y)
{
  if(x<y)
  {
    swap(x,y);
  }
  while(y>0)
  {
    ll r=x%y;
    x=y;
    y=r;
  }
  return x;
}
int main(){
  int n;cin>>n;
  ll x;cin>>x;
  VL y(n+1,0);
  REP(i,n){
    cin>>y[i];
  }
  y[n]=x;
  sort(y.begin(),y.end());
  ll past=y[1]-y[0];
  for(int i=0;i<n;i++){
    ll now=y[i+1]-y[i];
    past=gcd(past,now);
  }
  cout<<past<<endl;
}