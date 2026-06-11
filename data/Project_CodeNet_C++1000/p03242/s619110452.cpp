#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string a ;
    getline(cin,a);
    cout << 100*(58 - a[0]) + 10*(58 - a[1]) + 58 - a[2];
    return 0;
}
