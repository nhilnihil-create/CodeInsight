#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define ll long long
         
using namespace std;
     
long long gcd(int x, int y){
     if ( x == 0 ) return y;
     
     return gcd(y%x, x);
}
     
long long lcm(int x, int y){
     if ( y == 0 ){
          return x;
     }
     
     return x*y/gcd(x, y);
}
     
int min(int a, int b){
     return a > b ? b : a;
}
     
double max(double a, double b){
     return a > b ? a : b;
}

int main()
{
     cin.sync_with_stdio( false );

     ll r,d, x;
     cin>>r>>d>>x;

     for (int i=0;i<10;i++){
          ll dd = r*x-d;
          cout<<dd<<endl;
          x=dd;
     }
}