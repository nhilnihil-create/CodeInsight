#include <iostream>

using namespace std;

int main()
{
    int m = 0 ;
    string s;

    cin >> s ;
    if((s[0]) == '1')
    {
        m = m + 1 ;
    }
    if(s[1] == '1')
    {
        m = m + 1 ;
    }
    if(s[2] == '1')
    {
        m = m + 1 ;
    }
    cout << m << endl;
    return 0;
}
