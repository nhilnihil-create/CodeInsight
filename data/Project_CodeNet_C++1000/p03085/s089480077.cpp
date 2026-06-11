#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    string n ;
    cin >> n ;
    if (n == "A"){
        cout << "T" ;
    }
    if (n == "C"){
        cout << "G" ;
    }
    if (n == "G"){
        cout << "C" ;
    }
    if (n == "T"){
        cout << "A" ;
    }
    return 0;
}
