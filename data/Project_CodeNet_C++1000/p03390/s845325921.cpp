#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

signed main(){
  
  int q;
  cin>>q;
  
  while( q-- ){
    
    int a, b;
    cin>>a>>b;
    
    if( a > b ) swap( a, b );
    
    double x = sqrt( (double)a * b - 1 );
    
    int l = x;

    int r = ( (double)a * b - 1 ) / l;
    
    int ans = l * 2;
    
    if( l == r ) ans--;
    
    if( a <= l ) ans--;
    
    cout<<ans<<endl;
    
  }
    
  return 0;
}
