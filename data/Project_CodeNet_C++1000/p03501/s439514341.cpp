#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
    int a , n , b , c , m;
    cin >>n >> a >> b ;
    c = n * a ;
    m = min(c , b) ;
    cout << m ;
    return 0 ;
}
