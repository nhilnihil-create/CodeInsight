#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int ab = a+b;
    
    if (ab > c){
        cout << b + c << endl;
    }
    else {
        if (ab + 1 < c)
            c = ab + 1;
        cout << b + c << endl;
    }

    return 0;
}
