#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    double a, b, c;
    cin >> a >> b >> c;
    if(b / a >= c){
        cout << c << endl;
    }else{
        cout << (int)(b / a) << endl;
    }
    return 0;
}
