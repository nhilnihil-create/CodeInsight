#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;


void solve(){
  cin >> n;
  int x[n],y[n],h[n];
  int s=-1;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i]>0)s=i;
  }
  int rx=-1,ry=-1,rh=-1;
  for(int Cx=0;Cx<=100;Cx++){
    for(int Cy=0;Cy<=100;Cy++){
      bool f=true;
      int H=h[s]+abs(Cx-x[s])+abs(Cy-y[s]);
      for(int i=0;i<n;i++){
        if(h[i]>0 && H-h[i]!=abs(Cx-x[i])+abs(Cy-y[i]))f=false;
        if(h[i]==0 && H>abs(Cx-x[i])+abs(Cy-y[i]))f=false;
      }
      if(f){
        rx=Cx;
        ry=Cy;
        rh=H;
      }
    }
  }
  cout << rx << " " << ry << " " << rh << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
