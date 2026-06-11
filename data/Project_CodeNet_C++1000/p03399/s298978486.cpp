#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int mini_1 = min(a, b);
    int mini_2 = min(c,d);
    
    cout << mini_1 + mini_2 << endl;
}