#include <iostream>
using namespace std;
int main(void){
    long a, b, c;
    
    cin >> a >> b >> c;
    if(a + b + 1 >= c) cout << b + c << endl;
    else cout << a + b + 1 + b;
    
    return 0;
}
