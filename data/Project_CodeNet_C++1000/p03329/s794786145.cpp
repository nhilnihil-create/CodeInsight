#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int c[100005];  
  
int solve( int n ) {  
    int a = 101 , num[12] = { 1 , 6 , 36 , 216 , 1296 , 7776 , 46656 , 9  , 81 , 729 , 6561 , 59049 }; 
    if( n < 0 ) return 101;  
    if( n == 0 ) return 0;  
    if( c[n] != 0 ) return c[n];  
    for( int i = 0 ; i < 12 ; i++ ) a = min( a , solve( n - num[i] ) );  
    c[n] = a + 1;  
    return a + 1;  
}  
  
int main() {  
    int x;  
    cin >> x;  
    cout << solve(x);  
} 

