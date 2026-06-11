#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int big = max(a, c);
    int small = min( a, c);
    
    int abbig = max( a, b );
    int abmin = min( a, b );
    
    int cbbig = max( c, b );
    int cbmin = min ( c, b );
    
    if ( big - small <= d ){
        cout << "Yes" << endl;
    } else if ( abbig - abmin <= d && cbbig - cbmin <= d ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    
    }
}