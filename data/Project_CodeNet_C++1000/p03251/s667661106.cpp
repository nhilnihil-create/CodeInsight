#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

  
int main(){
  int n,m,x,y;
  cin >> n >> m >> x >>y;
  VI xx(n);
  VI yy(m);
  rep(i,n){
    cin >> xx.at(i);
  }
  rep(i,m){
    cin >> yy.at(i);
  }
  bool a=false;
  bool b=false;
  int xmax=-500;
  int ymin=500;
  rep(i,n){
    xmax=max(xmax,xx.at(i));
  }
  rep(i,m){
    ymin=min(ymin,yy.at(i));
  }
  if(xmax < y && xmax < ymin) a=true;
  if(x< y && x<ymin) b=true;
  
  if(a && b) cout << "No" << " " << "War" <<endl;
  else cout << "War" <<endl;
  
}
  