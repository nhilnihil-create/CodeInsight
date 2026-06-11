#include <iostream>

using namespace std;

int main()
{
    int a , b , t;
    cin>> a>>b>>t;
    if (a<=t ) {
        cout<< t/a*b;
    }
    else {
        cout<< 0;
    }
    return 0;
}
