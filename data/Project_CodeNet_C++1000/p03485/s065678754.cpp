#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b, x;
    cin >> a >> b;
    
    x = (a+b)/2;
    
    if(2*x == a+b)
    {
        cout << x << endl;
    }
    else
    {
        cout << x + 1 << endl;
    }
}
