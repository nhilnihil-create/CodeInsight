#include <iostream>

using namespace std;

int main()
{
    int tedad;
    char str[3];
    cin >> str;
    if(str[0] == '1')
    {
        tedad++ ;
    }
    if(str[1] == '1')
    {
        tedad++;
    }
    if(str[2] == '1')
    {
        tedad++;
    }
    cout << tedad;

    return 0;
}
