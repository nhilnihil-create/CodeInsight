#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a , b;
    cin>> a >> b;
    if (a>=13) {
        cout<< b;
    }
    else {
        if(a<=12) {
            if (a>=6) {
                cout<< b/2;
            }
            else{
                cout<< 0;
            }
        }
    }
    return 0;
}
