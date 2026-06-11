#include <iostream>

using namespace std;


int main()
{
    int a, b , n;
    cin>> n>> a>> b;
    if (a*n >= b){
        cout<< b;
    }
    else{
        cout<<a*n;
    }

    return 0;
}
