#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c == 'A')
        cout << 'T';
    else if (c == 'T')
        cout << 'A';
    else if (c == 'C')
        cout << 'G';
    else
        cout << 'C';
}
