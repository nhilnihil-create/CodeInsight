#include <iostream>

using namespace std;

int main()
{
    int a , b , c;
    int max = 0;
    int x = 0;
    cin >> a >> b >> c;
    max = a;
    x = max * 10 + b + c;
    if (max <= b){
        max = b;
        x = max * 10 + a + c;
    }
    if (max <= c){
        max = c;
        x = max * 10 + b + a;
    }
    cout << x;
    return 0;
}
