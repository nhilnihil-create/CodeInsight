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

int main(){
  int n;cin>>n;
  VL x(n),y(n),h(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i]>>h[i];
  }
  ll now=0;
  ll past=0;


  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      ll high=0;
      for(int r=0;r<n;r++){
        if(h[r]!=0){
          high=h[r]+abs(i-x[r])+abs(j-y[r]);
          break;
        }
      }
      int key=0;
      ll base=0;
      for(int r=0;r<n;r++){
        if(h[r]==max(high-abs(i-x[r])-abs(j-y[r]),base)){
          continue;
        }else{
          key=1;break;
        }
      }
      if(key==0){cout<<i<<" "<<j<<" "<<high<<endl;}
    }
  }
}