#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if(a < 9 && b < 9 && a + b <= 16){
        cout << "Yay!";
    }
    else {
        cout << ":(";
    }
    return 0;
}
