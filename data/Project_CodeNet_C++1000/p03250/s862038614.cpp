/*
 * a.cc:
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
#include<iomanip>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main(){
  int a,b,c;
  cin>>a>>b>>c;

  int x,y,z;

  x=10*a+b+c;
  y=10*b+a+c;
  z=10*c+a+b;

  cout<<max(max(x,y),z)<<endl;

}
