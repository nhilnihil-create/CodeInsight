#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    if (a == b) ans = c;
    if (b == c) ans = a;
    if (a == c) ans = b;
 
    cout << ans << endl;
    
}