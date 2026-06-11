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
     
int max(int a, int b){
     return a > b ? a : b;
}

int main()
{
     cin.sync_with_stdio( false );
     
     int n,m;
     cin>>n>>m;
     
     int l[m],r[m];
     for (int i=0;i<m;i++){
         cin>>l[i]>>r[i];
     }
     
     sort(l, l+m);
     sort(r, r+m);
     
     int res = r[0] - l[m-1] + 1;
     if ( res < 0 ){
         cout<<0<<endl;
     }else{
         cout<<res<<endl;
     }
}