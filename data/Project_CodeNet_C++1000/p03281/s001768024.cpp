#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, ans, sum, prime, tem;
    cin >> n;
   
   ans = 0;
   for ( int i = 1; i <= n ; i+=2 ) {
       sum = 1;
       tem = i;
       
       for ( int j = 2; j*j <= i ; j++ ) {
           if ( tem % j == 0 ) {
               prime = 0;
               
               while ( tem % j == 0 ) {
                   tem /= j;
                   prime++;
               }
               
               sum *= prime + 1;
           }
       }
       
       if ( tem > 1 ) {
           sum *= 2;
       }
       
       if ( sum == 8 ) {
           ans ++;
       }
    }
    cout << ans << endl;
   
    return (0);
}
