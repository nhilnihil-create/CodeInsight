#include <iostream>

using namespace std;

int main()
{
    int a , b , x;
    cin>> a >> b;
    if (a==b) {
        cout<< 2*a;
    }
    else {
        if (a>b) {
            x = a+a-1 ;
            cout<< x;
        }
        else {
            x = b+b-1;
            cout<< x;
        }

    }
    return 0;
}
