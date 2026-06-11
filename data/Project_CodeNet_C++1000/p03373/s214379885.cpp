#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {  
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int mincost;
  if(x==y) {
  	if(a+b > 2*c) {
    	mincost = 2*c*x;
    }
    else {
    	mincost += a*x+b*y;
    }
  }
  else if(x > y) {
  	  if(a+b > 2*c) {
    	mincost = 2*c*y;
        if(a*(x-y) > 2*c*(x-y)) {
        	mincost += 2*c*(x-y);
        }
        else mincost += a*(x-y);
    }
     else {
    	mincost += a*x+b*y;
    }
  }
  else {
  	if(a+b > 2*c) {
    	mincost = 2*c*x;
        if(b*(y-x) > 2*c*(y-x)) {
        	mincost += 2*c*(y-x);
        }
        else mincost += b*(y-x);
    }
     else {
    	mincost += a*x+b*y;
    }
  }
  cout << mincost << endl;
}