#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int d, m;
    d = 10 * (int(s[5]) - 48) + int(s[6]) - 48;
    m = 10 * (int(s[8]) - 48) + int(s[9]) - 48;
    if(d <= 4 && m <= 30)
    cout << "Heisei";
    else
    cout << "TBD";
    return 0;
}