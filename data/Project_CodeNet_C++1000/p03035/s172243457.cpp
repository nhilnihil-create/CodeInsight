#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a , b , m ;
    cin >> a >> b ;
    if(a < 13){
        if(a < 6){
            m = 0 ;
        }
        else{
            m = b/2 ;
        }
    }
    else{
        m = b ;
    }
    cout << m ;
    return 0;
}
