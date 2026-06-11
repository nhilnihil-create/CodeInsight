#include <iostream>

using namespace std;

int main()
{

    string x;
    getline(cin, x);
    cout << x[0] + x[1] + x[2] - 144;
    return 0;
}
