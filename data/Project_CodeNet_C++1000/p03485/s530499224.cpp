#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    double x = (a + b)/2.0;

    if( x > int(x) ) x = int(x) + 1; 
    cout << x << endl;
}
    
