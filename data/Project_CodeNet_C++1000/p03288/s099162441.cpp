#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a <= 1199){
        cout << "ABC";
    }else if (a <= 2799){
        cout << "ARC";
    }else{
        cout << "AGC";
    }
    return 0;
}
