#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int flg_a = 0, flg_b = 0, flg_c = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'a')
        {
            flg_a++;
        }
        else if (s[i] == 'b')
        {
            flg_b++;
        }
        else if (s[i] == 'c')
        {
            flg_c++;
        }
    }
    if (flg_a == 1 && flg_b == 1 && flg_c == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
