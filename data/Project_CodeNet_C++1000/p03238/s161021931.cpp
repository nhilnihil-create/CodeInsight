#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    int n, a, b;
    cin >> n;
    if(n == 1){
        cout << "Hello World" << endl;
    }else if(n == 2){
        cin >> a >> b;
        cout << a + b << endl;
    }
    
    return 0;
}