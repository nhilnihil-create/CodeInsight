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
  vector<vector<int>> c(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  int pa1=c[0][1]-c[0][0];
  int pa2=c[0][2]-c[0][0];
  for(int i=0;i<3;i++){
    int t1=c[i][1]-c[i][0];
    int t2=c[i][2]-c[i][0];
    if(pa1==t1&&pa2==t2){
      continue;
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  pa1=c[1][0]-c[0][0];
  pa2=c[2][0]-c[0][0];
  for(int i=0;i<3;i++){
    int t1=c[1][i]-c[0][i];
    int t2=c[2][i]-c[0][i];
    if(pa1==t1&&pa2==t2){
      continue;
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;

}