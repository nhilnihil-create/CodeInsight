#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
#include <bitset>
#include <sstream>
#include <cstdio>
#include <complex>
#include <cstring>
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)
#define vi vector<int> 
#define pb(a) push_back(a)
int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

int main(void){
  string s;
  int x,y;
  cin>>s>>x>>y;

  vi dx, dy;
  int rl = 0;
  bool isx = true;

  rep(i, s.size()){
    if(s[i] == 'F'){
      rl ++;
    } else {
      if(isx){
	dx.pb(rl);
      } else {
	dy.pb(rl);
      }
      rl = 0;
      isx = !isx;
    }
  }

  if(isx){
    dx.pb(rl);
  } else {
    dy.pb(rl);
  }
  const int geta = 8000;

  bitset<16010> dpx, dpy;
  dpx.set(dx[0] + geta);
  dpy.set(0+geta);

  dx.erase(dx.begin());

  rep(i,dx.size()){
    dpx = (dpx << dx[i]) | (dpx >> dx[i]);
  }

  rep(i,dy.size()){
    dpy = (dpy << dy[i]) | (dpy >> dy[i]);
  }

  bool res = dpx[x + geta] && dpy[y + geta];

  cout<<(res?"Yes":"No")<<endl;
}
