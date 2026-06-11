#include <iostream>

using namespace std;

int main()
{
    int a , b , c , i = 0;
    cin >> a >> b >> c;
    while (b != 0 && c != 0 && b >= a){
        b -= a;
        c--;
        i++;
    }
    cout << i;
    return 0;
}
