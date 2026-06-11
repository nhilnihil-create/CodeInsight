#include <iostream>
#include <string>

using namespace std;

int main()
{
    char s;
    int value = 700;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        // cout << s << endl;
        if (s == 'o')
        {
            value += 100;
        }
    }
    cout << value << endl;
    return 0;
}
